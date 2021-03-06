
IF (Qt5Core_FOUND)
  # FindQt4.cmake wasn't used, so define it here
  MACRO (QT4_GET_MOC_INC_DIRS _moc_INC_DIRS)
     SET(${_moc_INC_DIRS})
     GET_DIRECTORY_PROPERTY(_inc_DIRS INCLUDE_DIRECTORIES)

     FOREACH(_current ${_inc_DIRS})
        SET(${_moc_INC_DIRS} ${${_moc_INC_DIRS}} "-I" ${_current})
     ENDFOREACH(_current ${_inc_DIRS})
  ENDMACRO(QT4_GET_MOC_INC_DIRS)

  MACRO(SETUP_QT5_DIRS)
    GET_TARGET_PROPERTY(QMAKE_EXECUTABLE ${Qt5Core_QMAKE_EXECUTABLE} LOCATION)
    EXEC_PROGRAM( ${QMAKE_EXECUTABLE} ARGS "-query QT_INSTALL_LIBS" OUTPUT_VARIABLE QT_LIBRARY_DIR )
    EXEC_PROGRAM( ${QMAKE_EXECUTABLE} ARGS "-query QT_INSTALL_PREFIX" OUTPUT_VARIABLE QT_PREFIX_DIR )
    EXEC_PROGRAM( ${QMAKE_EXECUTABLE} ARGS "-query QT_INSTALL_PLUGINS" OUTPUT_VARIABLE QT_PLUGINS_DIR )
    EXEC_PROGRAM( ${QMAKE_EXECUTABLE} ARGS "-query QT_INSTALL_BINS" OUTPUT_VARIABLE QT_BINARY_DIR )
    EXEC_PROGRAM( ${QMAKE_EXECUTABLE} ARGS "-query QT_INSTALL_HEADERS" OUTPUT_VARIABLE QT_INCLUDE_DIR )
    EXEC_PROGRAM( ${QMAKE_EXECUTABLE} ARGS "-query QT_INSTALL_DOCS" OUTPUT_VARIABLE QT_DOC_DIR )
    EXEC_PROGRAM( ${QMAKE_EXECUTABLE} ARGS "-query QT_INSTALL_DATA" OUTPUT_VARIABLE QT_DATA_DIR )
    EXEC_PROGRAM( ${QMAKE_EXECUTABLE} ARGS "-query QT_INSTALL_ARCHDATA" OUTPUT_VARIABLE QT_ARCHDATA_DIR )
    SET( QT_MKSPECS_DIR "${QT_ARCHDATA_DIR}/mkspecs" )
  ENDMACRO(SETUP_QT5_DIRS)
ENDIF()

MACRO(MY_AUTOMOC _srcsList)
  QT4_GET_MOC_INC_DIRS(_moc_INCS)
  FOREACH (_current_FILE ${${_srcsList}})
    GET_FILENAME_COMPONENT(_abs_FILE ${_current_FILE} ABSOLUTE)
    GET_FILENAME_COMPONENT(_basename ${_current_FILE} NAME_WE)
    SET(_moc ${CMAKE_CURRENT_BINARY_DIR}/${_basename}.moc)
    SET(extra_moc_argument)
    if(WIN32)
       SET(extra_moc_argument -DWIN32)
    endif(WIN32)
    ADD_CUSTOM_COMMAND(OUTPUT ${_moc}
                       COMMAND ${QT_MOC_EXECUTABLE}
                       ARGS ${extra_moc_argument} ${_moc_INCS} -o ${_moc} ${_abs_FILE}
                       DEPENDS ${_current_FILE}
    )
    LIST(APPEND ${_srcsList} ${_moc})
  ENDFOREACH (_current_FILE)
ENDMACRO(MY_AUTOMOC)
