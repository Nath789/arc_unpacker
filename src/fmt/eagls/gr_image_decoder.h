#pragma once

#include "fmt/image_decoder.h"

namespace au {
namespace fmt {
namespace eagls {

    class GrImageDecoder final : public ImageDecoder
    {
    protected:
        bool is_recognized_impl(io::File &input_file) const override;
        pix::Image decode_impl(io::File &input_file) const override;
    };

} } }
