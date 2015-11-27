#pragma once

#include "fmt/image_decoder.h"

namespace au {
namespace fmt {
namespace alice_soft {

    class PmsImageDecoder final : public ImageDecoder
    {
    public:
        static bstr decompress_8bit(
            io::Stream &input_stream, const size_t width, const size_t height);

        static bstr decompress_16bit(
            io::Stream &input_stream, const size_t width, const size_t height);

    protected:
        bool is_recognized_impl(io::File &input_file) const override;
        pix::Image decode_impl(io::File &input_file) const override;
    };

} } }
