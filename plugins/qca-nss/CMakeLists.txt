SET(QCA_NSS_SOURCES qca-nss.cpp)

ADD_DEFINITIONS(${NSS_DEFINITIONS})

INCLUDE_DIRECTORIES(${NSS_INCLUDE_DIR})

MY_AUTOMOC( QCA_NSS_SOURCES )

ADD_LIBRARY(qca-nss MODULE ${QCA_NSS_SOURCES})

TARGET_LINK_LIBRARIES(qca-nss ${QT_QTCORE_LIBRARY} ${QCA_LIB_NAME} ${NSS_LIBRARIES})

INSTALL(TARGETS qca-nss
        LIBRARY DESTINATION "${QCA_PLUGINS_INSTALL_DIR}"
        ARCHIVE DESTINATION "${QCA_PLUGINS_INSTALL_DIR}"
        RUNTIME DESTINATION "${QCA_PLUGINS_INSTALL_DIR}"
)
