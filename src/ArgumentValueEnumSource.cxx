/**
 * Copyright (C) 2015-2017 Virgil Security Inc.
 *
 * Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     (1) Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *     (2) Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *
 *     (3) Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <cli/argument/ArgumentValueEnumSource.h>

#include <cli/memory.h>
#include <cli/crypto/Crypto.h>

using cli::Crypto;
using cli::argument::ArgumentSource;
using cli::argument::ArgumentValueEnumSource;
using cli::argument::ArgumentSourceType;
using cli::model::KeyAlgorithm;
using cli::model::PublicKey;
using cli::model::PrivateKey;
using cli::model::Password;
using cli::model::Card;
using cli::model::HashAlgorithm;

const char* ArgumentValueEnumSource::doGetName() const {
    return "ArgumentValueEnumSource";
}

ArgumentSourceType ArgumentValueEnumSource::doGetType() const {
    return ArgumentSourceType::Parser;
}

void ArgumentValueEnumSource::doInit(const ArgumentSource& argumentSource) {
    (void)argumentSource;
}

std::unique_ptr<KeyAlgorithm> ArgumentValueEnumSource::doReadKeyAlgorithm(const ArgumentValue& argumentValue) const {
    return std::make_unique<KeyAlgorithm>(cli::model::key_algorithm_from(argumentValue.value()));
}

std::unique_ptr<HashAlgorithm> ArgumentValueEnumSource::doReadHashAlgorithm(const ArgumentValue& argumentValue) const {
    return std::make_unique<HashAlgorithm>(cli::model::hash_algorithm_from(argumentValue.value()));
}
