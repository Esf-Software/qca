ENABLE_TESTING()

set(pkits_bin_SRCS pkits.cpp)

MY_AUTOMOC( pkits_bin_SRCS )

add_executable(pkits ${pkits_bin_SRCS} )

target_link_libraries( pkits ${QCA_LIB_NAME} ${QT_QTTEST_LIBRARY})

FOREACH( testFileName BadnotAfterDateCACert.crt RFC3280MandatoryAttributeTypesCACRL.crl BadnotAfterDateCACRL.crl
	 RFC3280OptionalAttributeTypesCACert.crt BadnotBeforeDateCACert.crt RFC3280OptionalAttributeTypesCACRL.crl
	 BadnotBeforeDateCACRL.crl RolloverfromPrintableStringtoUTF8StringCACert.crt BadSignedCACert.crt 
	 RolloverfromPrintableStringtoUTF8StringCACRL.crl BadSignedCACRL.crl TrustAnchorRootCertificate.crt
	 DSACACert.crt TrustAnchorRootCRL.crl DSACACRL.crl UIDCACert.crt DSAParametersInheritedCACert.crt
	 UIDCACRL.crl DSAParametersInheritedCACRL.crl UTF8StringCaseInsensitiveMatchCACert.crt
	 GoodCACert.crt UTF8StringCaseInsensitiveMatchCACRL.crl GoodCACRL.crl UTF8StringEncodedNamesCACert.crt
	 InvalidCAnotAfterDateTest5EE.crt UTF8StringEncodedNamesCACRL.crl InvalidCAnotBeforeDateTest1EE.crt
	 ValidCertificatePathTest1EE.crt InvalidCASignatureTest2EE.crt ValidDSAParameterInheritanceTest5EE.crt
	 InvalidDSASignatureTest6EE.crt ValidDSASignaturesTest4EE.crt
	 InvalidEEnotAfterDateTest6EE.crt ValidGeneralizedTimenotAfterDateTest8EE.crt
	 InvalidEEnotBeforeDateTest2EE.crt ValidGeneralizedTimenotBeforeDateTest4EE.crt
	 InvalidEESignatureTest3EE.crt ValidNameChainingCapitalizationTest5EE.crt
	 InvalidMissingCRLTest1EE.crt ValidNameChainingWhitespaceTest3EE.crt
	 InvalidNameChainingOrderTest2EE.crt ValidNameChainingWhitespaceTest4EE.crt
	 InvalidNameChainingTest1EE.crt ValidNameUIDsTest6EE.crt
	 Invalidpre2000UTCEEnotAfterDateTest7EE.crt Validpre2000UTCnotBeforeDateTest3EE.crt
	 InvalidRevokedCATest2EE.crt ValidRFC3280MandatoryAttributeTypesTest7EE.crt
	 InvalidRevokedEETest3EE.crt ValidRFC3280OptionalAttributeTypesTest8EE.crt
	 NoCRLCACert.crt ValidRolloverfromPrintableStringtoUTF8StringTest10EE.crt
	 RevokedsubCACert.crt ValidUTF8StringCaseInsensitiveMatchTest11EE.crt
	 RevokedsubCACRL.crl ValidUTF8StringEncodedNamesTest9EE.crt RFC3280MandatoryAttributeTypesCACert.crt )
   CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/certs/${testFileName} ${CMAKE_CURRENT_BINARY_DIR}/certs/${testFileName} COPYONLY)
ENDFOREACH( testFileName )

ADD_TEST(PublicKeyInfrastructure ${EXECUTABLE_OUTPUT_PATH}/pkits)
