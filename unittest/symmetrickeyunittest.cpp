/**
 * symmetrickeyunittest.cpp
 *
 * Copyright (C)  2004  Brad Hards <bradh@frogmouth.net>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "symmetrickeyunittest.h"
#include "qca.h"

SymmetricKeyUnitTest::SymmetricKeyUnitTest()
    : Tester()
{

}

void SymmetricKeyUnitTest::allTests()
{
    QCA::Initializer init;

    QCA::SymmetricKey emptyKey;
    CHECK( emptyKey.size(), (unsigned int) 0 );

    QCA::SymmetricKey randomKey(10);
    CHECK( randomKey.size(), (unsigned int) 10 );

    QByteArray byteArray(10);
    byteArray.fill( 'c' );
    QSecureArray secureArray( byteArray );
    QCA::SymmetricKey keyArray = secureArray;
    CHECK( secureArray.size(), (unsigned int) 10 );
    CHECK( keyArray.size(), secureArray.size() );
    CHECK( QCA::arrayToHex ( keyArray ), QString( "63636363636363636363" ) );
    CHECK( QCA::arrayToHex ( secureArray ), QString( "63636363636363636363" ) );
    keyArray[3] = 0x00; // test keyArray detaches OK
    CHECK( QCA::arrayToHex ( keyArray ), QString( "63636300636363636363" ) );
    CHECK( QCA::arrayToHex ( secureArray ), QString( "63636363636363636363" ) );

    QCA::SymmetricKey anotherKey;
    anotherKey = keyArray;
    CHECK( QCA::arrayToHex ( anotherKey ), QString( "63636300636363636363" ) );
    QCA::SymmetricKey bigKey( 100 );
    anotherKey = bigKey;
    CHECK( anotherKey.size(), (unsigned int) 100 );
    anotherKey = secureArray;
    CHECK( QCA::arrayToHex ( secureArray ), QString( "63636363636363636363" ) );
    CHECK( anotherKey.size(), (unsigned int) 10 );
    anotherKey = emptyKey;
    CHECK( anotherKey.size(), (unsigned int) 0 );
}
