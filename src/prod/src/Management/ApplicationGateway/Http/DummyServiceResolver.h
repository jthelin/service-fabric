// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#pragma once

namespace HttpApplicationGateway
{
    class DummyServiceResolver
        : public IServiceResolver
        , public Common::TextTraceComponent<Common::TraceTaskCodes::HttpApplicationGateway>
    {
    public:
        DummyServiceResolver()
        {};

        ~DummyServiceResolver() {}

        Common::AsyncOperationSPtr BeginOpen(
            Common::TimeSpan &timeout,
            Common::AsyncCallback const &callback,
            Common::AsyncOperationSPtr const &parent);
        Common::ErrorCode EndOpen(Common::AsyncOperationSPtr const &operation);

        Common::AsyncOperationSPtr BeginPrefixResolveServicePartition(
            ParsedGatewayUriSPtr const &parsedUri,
            Api::IResolvedServicePartitionResultPtr &prevResult,
            std::wstring const &traceId,
            KAllocator &allocator,
            Common::TimeSpan &timeout,
            Common::AsyncCallback const &callback,
            Common::AsyncOperationSPtr const &parent);

        Common::ErrorCode EndResolveServicePartition(
            Common::AsyncOperationSPtr const &operation,
            Api::IResolvedServicePartitionResultPtr &prevResult);

        Common::ErrorCode GetReplicaEndpoint(
            Api::IResolvedServicePartitionResultPtr const &rspResult,
            TargetReplicaSelector::Enum targetReplicaSelector,
            __out std::wstring &);

        std::wstring GetServiceName(Api::IResolvedServicePartitionResultPtr const &rspResult);
    };
}
