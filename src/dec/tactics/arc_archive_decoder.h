#pragma once

#include "dec/base_archive_decoder.h"

namespace au {
namespace dec {
namespace tactics {

    enum class CompressionMethod : u8
    {
        PlainLzss,
        VariableLzss,
    };

    class ArcArchiveDecoder final : public BaseArchiveDecoder
    {
    public:
        ArcArchiveDecoder();
        std::vector<std::string> get_linked_formats() const override;

    protected:
        bool is_recognized_impl(io::File &input_file) const override;

        std::unique_ptr<ArchiveMeta> read_meta_impl(
            const Logger &logger,
            io::File &input_file) const override;

        std::unique_ptr<io::File> read_file_impl(
            const Logger &logger,
            io::File &input_file,
            const ArchiveMeta &m,
            const ArchiveEntry &e) const override;

    public:
        bstr key;
        CompressionMethod compression_method;
    };

} } }
