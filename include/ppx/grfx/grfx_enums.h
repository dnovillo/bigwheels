// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ppx_grfx_enums_h
#define ppx_grfx_enums_h

namespace ppx {
namespace grfx {

enum Api
{
    API_UNDEFINED = 0,
    API_VK_1_1    = (1 << 16) | (1 << 0),
    API_VK_1_2    = (1 << 16) | (2 << 0),
    API_VK_1_3    = (1 << 16) | (3 << 0),
    API_DX_12_0   = (12 << 16) | (0 << 0),
    API_DX_12_1   = (12 << 16) | (1 << 0),
};

enum AttachmentLoadOp
{
    ATTACHMENT_LOAD_OP_LOAD = 0,
    ATTACHMENT_LOAD_OP_CLEAR,
    ATTACHMENT_LOAD_OP_DONT_CARE,
};

enum AttachmentStoreOp
{
    ATTACHMENT_STORE_OP_STORE = 0,
    ATTACHMENT_STORE_OP_DONT_CARE,
};

enum BlendFactor
{
    BLEND_FACTOR_ZERO                     = 0,
    BLEND_FACTOR_ONE                      = 1,
    BLEND_FACTOR_SRC_COLOR                = 2,
    BLEND_FACTOR_ONE_MINUS_SRC_COLOR      = 3,
    BLEND_FACTOR_DST_COLOR                = 4,
    BLEND_FACTOR_ONE_MINUS_DST_COLOR      = 5,
    BLEND_FACTOR_SRC_ALPHA                = 6,
    BLEND_FACTOR_ONE_MINUS_SRC_ALPHA      = 7,
    BLEND_FACTOR_DST_ALPHA                = 8,
    BLEND_FACTOR_ONE_MINUS_DST_ALPHA      = 9,
    BLEND_FACTOR_CONSTANT_COLOR           = 10,
    BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR = 11,
    BLEND_FACTOR_CONSTANT_ALPHA           = 12,
    BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA = 13,
    BLEND_FACTOR_SRC_ALPHA_SATURATE       = 14,
    BLEND_FACTOR_SRC1_COLOR               = 15,
    BLEND_FACTOR_ONE_MINUS_SRC1_COLOR     = 16,
    BLEND_FACTOR_SRC1_ALPHA               = 17,
    BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA     = 18,
};

//! Some basic blend modes to make basic graphics pipelines a bit more manageable.
//! Premultipled cases not explicitly handled.
//!
enum BlendMode
{
    BLEND_MODE_NONE          = 0,
    BLEND_MODE_ADDITIVE      = 1,
    BLEND_MODE_ALPHA         = 2,
    BLEND_MODE_OVER          = 3,
    BLEND_MODE_UNDER         = 4,
    BLEND_MODE_PREMULT_ALPHA = 5,
};

enum BlendOp
{
    BLEND_OP_ADD              = 0,
    BLEND_OP_SUBTRACT         = 1,
    BLEND_OP_REVERSE_SUBTRACT = 2,
    BLEND_OP_MIN              = 3,
    BLEND_OP_MAX              = 4,

#if defined(PPX_VK_BLEND_OPERATION_ADVANCED)
    // Provdied by VK_blend_operation_advanced
    BLEND_OP_ZERO               = 1000148000,
    BLEND_OP_SRC                = 1000148001,
    BLEND_OP_DST                = 1000148002,
    BLEND_OP_SRC_OVER           = 1000148003,
    BLEND_OP_DST_OVER           = 1000148004,
    BLEND_OP_SRC_IN             = 1000148005,
    BLEND_OP_DST_IN             = 1000148006,
    BLEND_OP_SRC_OUT            = 1000148007,
    BLEND_OP_DST_OUT            = 1000148008,
    BLEND_OP_SRC_ATOP           = 1000148009,
    BLEND_OP_DST_ATOP           = 1000148010,
    BLEND_OP_XOR                = 1000148011,
    BLEND_OP_MULTIPLY           = 1000148012,
    BLEND_OP_SCREEN             = 1000148013,
    BLEND_OP_OVERLAY            = 1000148014,
    BLEND_OP_DARKEN             = 1000148015,
    BLEND_OP_LIGHTEN            = 1000148016,
    BLEND_OP_COLORDODGE         = 1000148017,
    BLEND_OP_COLORBURN          = 1000148018,
    BLEND_OP_HARDLIGHT          = 1000148019,
    BLEND_OP_SOFTLIGHT          = 1000148020,
    BLEND_OP_DIFFERENCE         = 1000148021,
    BLEND_OP_EXCLUSION          = 1000148022,
    BLEND_OP_INVERT             = 1000148023,
    BLEND_OP_INVERT_RGB         = 1000148024,
    BLEND_OP_LINEARDODGE        = 1000148025,
    BLEND_OP_LINEARBURN         = 1000148026,
    BLEND_OP_VIVIDLIGHT         = 1000148027,
    BLEND_OP_LINEARLIGHT        = 1000148028,
    BLEND_OP_PINLIGHT           = 1000148029,
    BLEND_OP_HARDMIX            = 1000148030,
    BLEND_OP_HSL_HUE            = 1000148031,
    BLEND_OP_HSL_SATURATION     = 1000148032,
    BLEND_OP_HSL_COLOR          = 1000148033,
    BLEND_OP_HSL_LUMINOSITY     = 1000148034,
    BLEND_OP_PLUS               = 1000148035,
    BLEND_OP_PLUS_CLAMPED       = 1000148036,
    BLEND_OP_PLUS_CLAMPED_ALPHA = 1000148037,
    BLEND_OP_PLUS_DARKER        = 1000148038,
    BLEND_OP_MINUS              = 1000148039,
    BLEND_OP_MINUS_CLAMPED      = 1000148040,
    BLEND_OP_CONTRAST           = 1000148041,
    BLEND_OP_INVERT_OVG         = 1000148042,
    BLEND_OP_RED                = 1000148043,
    BLEND_OP_GREEN              = 1000148044,
    BLEND_OP_BLUE               = 1000148045,
#endif // defined(PPX_VK_BLEND_OPERATION_ADVANCED)
};

enum BorderColor
{
    BORDER_COLOR_FLOAT_TRANSPARENT_BLACK = 0,
    BORDER_COLOR_INT_TRANSPARENT_BLACK   = 1,
    BORDER_COLOR_FLOAT_OPAQUE_BLACK      = 2,
    BORDER_COLOR_INT_OPAQUE_BLACK        = 3,
    BORDER_COLOR_FLOAT_OPAQUE_WHITE      = 4,
    BORDER_COLOR_INT_OPAQUE_WHITE        = 5,
};

enum BufferUsageFlagBits
{
    BUFFER_USAGE_TRANSFER_SRC                      = 0x00000001,
    BUFFER_USAGE_TRANSFER_DST                      = 0x00000002,
    BUFFER_USAGE_UNIFORM_TEXEL_BUFFER              = 0x00000004,
    BUFFER_USAGE_STORAGE_TEXEL_BUFFER              = 0x00000008,
    BUFFER_USAGE_UNIFORM_BUFFER                    = 0x00000010,
    BUFFER_USAGE_STORAGE_BUFFER                    = 0x00000020,
    BUFFER_USAGE_INDEX_BUFFER                      = 0x00000040,
    BUFFER_USAGE_VERTEX_BUFFER                     = 0x00000080,
    BUFFER_USAGE_INDIRECT_BUFFER                   = 0x00000100,
    BUFFER_USAGE_CONDITIONAL_RENDERING             = 0x00000200,
    BUFFER_USAGE_RAY_TRACING                       = 0x00000400,
    BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER         = 0x00000800,
    BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER = 0x00001000,
    BUFFER_USAGE_SHADER_DEVICE_ADDRESS             = 0x00002000,
};

enum ChromaLocation
{
    // Specifies that downsampled chroma samples are aligned with even
    // luma sample coordinates.
    CHROMA_LOCATION_COSITED_EVEN = 0,
    // Specifies that downsampled chroma samples are located between even
    // luma sample coordinates and the next higher odd luma sample coordinate.
    CHROMA_LOCATION_MIDPOINT = 1,
};

enum ColorComponentFlagBits
{
    COLOR_COMPONENT_R = 0x00000001,
    COLOR_COMPONENT_G = 0x00000002,
    COLOR_COMPONENT_B = 0x00000004,
    COLOR_COMPONENT_A = 0x00000008,
};

enum CompareOp
{
    COMPARE_OP_NEVER            = 0,
    COMPARE_OP_LESS             = 1,
    COMPARE_OP_EQUAL            = 2,
    COMPARE_OP_LESS_OR_EQUAL    = 3,
    COMPARE_OP_GREATER          = 4,
    COMPARE_OP_NOT_EQUAL        = 5,
    COMPARE_OP_GREATER_OR_EQUAL = 6,
    COMPARE_OP_ALWAYS           = 7,
};

enum CommandType
{
    COMMAND_TYPE_UNDEFINED = 0,
    COMMAND_TYPE_GRAPHICS  = 1,
    COMMAND_TYPE_COMPUTE   = 2,
    COMMAND_TYPE_TRANSFER  = 3,
};

enum ComponentSwizzle
{
    COMPONENT_SWIZZLE_IDENTITY = 0,
    COMPONENT_SWIZZLE_ZERO     = 1,
    COMPONENT_SWIZZLE_ONE      = 2,
    COMPONENT_SWIZZLE_R        = 3,
    COMPONENT_SWIZZLE_G        = 4,
    COMPONENT_SWIZZLE_B        = 5,
    COMPONENT_SWIZZLE_A        = 6,
};

enum CullMode
{
    CULL_MODE_NONE  = 0,
    CULL_MODE_FRONT = 1,
    CULL_MODE_BACK  = 2,
};

enum D3DDescriptorType
{
    D3D_DESCRIPTOR_TYPE_UNDEFINED = 0,
    D3D_DESCRIPTOR_TYPE_CBV       = 1,
    D3D_DESCRIPTOR_TYPE_SRV       = 2,
    D3D_DESCRIPTOR_TYPE_UAV       = 3,
    D3D_DESCRIPTOR_TYPE_SAMPLER   = 4,
};

enum ClearFlagBits
{
    CLEAR_FLAG_DEPTH   = 0x1,
    CLEAR_FLAG_STENCIL = 0x2,
};

enum DescriptorType
{
    // NOTE: These *DO NOT* match the enums in Vulkan
    //
    DESCRIPTOR_TYPE_UNDEFINED              = 0,
    DESCRIPTOR_TYPE_SAMPLER                = 1,  // Sampler
    DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER = 2,  // Combined image and sampler (Vulkan only)
    DESCRIPTOR_TYPE_SAMPLED_IMAGE          = 3,  // RO image object
    DESCRIPTOR_TYPE_STORAGE_IMAGE          = 4,  // RW image object
    DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER   = 5,  // RO texel buffer object
    DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER   = 6,  // RW texel buffer object
    DESCRIPTOR_TYPE_UNIFORM_BUFFER         = 7,  // constant/uniform buffer object
    DESCRIPTOR_TYPE_RAW_STORAGE_BUFFER     = 8,  // RW raw buffer object
    DESCRIPTOR_TYPE_RO_STRUCTURED_BUFFER   = 9,  // RO structured buffer object
    DESCRIPTOR_TYPE_RW_STRUCTURED_BUFFER   = 10, // RW structured buffer object
    DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC = 11, // (Vulkan only)
    DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC = 12, // (Vulkan only)
    DESCRIPTOR_TYPE_INPUT_ATTACHMENT       = 13, // (Vulkan only)
};

enum DrawPassClearFlagBits
{
    DRAW_PASS_CLEAR_FLAG_CLEAR_RENDER_TARGETS = 0x1,
    DRAW_PASS_CLEAR_FLAG_CLEAR_DEPTH          = 0x2,
    DRAW_PASS_CLEAR_FLAG_CLEAR_STENCIL        = 0x4,
    DRAW_PASS_CLEAR_FLAG_CLEAR_ALL            = DRAW_PASS_CLEAR_FLAG_CLEAR_RENDER_TARGETS | DRAW_PASS_CLEAR_FLAG_CLEAR_DEPTH | DRAW_PASS_CLEAR_FLAG_CLEAR_STENCIL,
};

enum Filter
{
    FILTER_NEAREST = 0,
    FILTER_LINEAR  = 1,
};

enum ShadingRateMode
{
    SHADING_RATE_NONE = 0,
    SHADING_RATE_FDM  = 1, // Fragment Density Map
    SHADING_RATE_VRS  = 2, // Variable Rate Shading
};

enum FrontFace
{
    FRONT_FACE_CCW = 0, // Counter clockwise
    FRONT_FACE_CW  = 1, // Clockwise
};

enum ImageType
{
    IMAGE_TYPE_UNDEFINED = 0,
    IMAGE_TYPE_1D        = 1,
    IMAGE_TYPE_2D        = 2,
    IMAGE_TYPE_3D        = 3,
    IMAGE_TYPE_CUBE      = 6,
};

enum ImageUsageFlagBits
{
    IMAGE_USAGE_TRANSFER_SRC             = 0x00000001,
    IMAGE_USAGE_TRANSFER_DST             = 0x00000002,
    IMAGE_USAGE_SAMPLED                  = 0x00000004,
    IMAGE_USAGE_STORAGE                  = 0x00000008,
    IMAGE_USAGE_COLOR_ATTACHMENT         = 0x00000010,
    IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT = 0x00000020,
    IMAGE_USAGE_TRANSIENT_ATTACHMENT     = 0x00000040,
    IMAGE_USAGE_INPUT_ATTACHMENT         = 0x00000080,
    IMAGE_USAGE_SHADING_RATE_IMAGE_NV    = 0x00000100,
    IMAGE_USAGE_FRAGMENT_DENSITY_MAP     = 0x00000200,
};

enum ImageViewType
{
    IMAGE_VIEW_TYPE_UNDEFINED  = 0,
    IMAGE_VIEW_TYPE_1D         = 1,
    IMAGE_VIEW_TYPE_2D         = 2,
    IMAGE_VIEW_TYPE_3D         = 3,
    IMAGE_VIEW_TYPE_CUBE       = 4,
    IMAGE_VIEW_TYPE_1D_ARRAY   = 5,
    IMAGE_VIEW_TYPE_2D_ARRAY   = 6,
    IMAGE_VIEW_TYPE_CUBE_ARRAY = 7,
};

enum IndexType
{
    INDEX_TYPE_UNDEFINED = 0,
    INDEX_TYPE_UINT16    = 1,
    INDEX_TYPE_UINT32    = 2,
};

enum LogicOp
{
    LOGIC_OP_CLEAR         = 0,
    LOGIC_OP_AND           = 1,
    LOGIC_OP_AND_REVERSE   = 2,
    LOGIC_OP_COPY          = 3,
    LOGIC_OP_AND_INVERTED  = 4,
    LOGIC_OP_NO_OP         = 5,
    LOGIC_OP_XOR           = 6,
    LOGIC_OP_OR            = 7,
    LOGIC_OP_NOR           = 8,
    LOGIC_OP_EQUIVALENT    = 9,
    LOGIC_OP_INVERT        = 10,
    LOGIC_OP_OR_REVERSE    = 11,
    LOGIC_OP_COPY_INVERTED = 12,
    LOGIC_OP_OR_INVERTED   = 13,
    LOGIC_OP_NAND          = 14,
    LOGIC_OP_SET           = 15,
};

enum MemoryUsage
{
    MEMORY_USAGE_UNKNOWN    = 0,
    MEMORY_USAGE_GPU_ONLY   = 1,
    MEMORY_USAGE_CPU_ONLY   = 2,
    MEMORY_USAGE_CPU_TO_GPU = 3,
    MEMORY_USAGE_GPU_TO_CPU = 4,
};

//
// VK: Maps to top/bottom of pipeline stages for timestamp queries.
// DX: Maps to begin/end for timestamp queries.
//
enum PipelineStage
{
    PIPELINE_STAGE_TOP_OF_PIPE_BIT    = 0,
    PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT = 1,
};

enum PolygonMode
{
    POLYGON_MODE_FILL  = 0,
    POLYGON_MODE_LINE  = 1,
    POLYGON_MODE_POINT = 2,
};

enum PresentMode
{
    PRESENT_MODE_UNDEFINED = 0,
    PRESENT_MODE_FIFO,
    PRESENT_MODE_MAILBOX,
    PRESENT_MODE_IMMEDIATE,
};

enum PrimitiveTopology
{
    PRIMITIVE_TOPOLOGY_TRIANGLE_LIST  = 0,
    PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP = 1,
    PRIMITIVE_TOPOLOGY_TRIANGLE_FAN   = 2,
    PRIMITIVE_TOPOLOGY_POINT_LIST     = 3,
    PRIMITIVE_TOPOLOGY_LINE_LIST      = 4,
    PRIMITIVE_TOPOLOGY_LINE_STRIP     = 5,
    PRIMITIVE_TOPOLOGY_PATCH_LIST     = 6,
};

enum QueryType
{
    QUERY_TYPE_UNDEFINED           = 0,
    QUERY_TYPE_OCCLUSION           = 1,
    QUERY_TYPE_PIPELINE_STATISTICS = 2,
    QUERY_TYPE_TIMESTAMP           = 3,
};

enum ResourceState
{
    RESOURCE_STATE_UNDEFINED = 0,
    RESOURCE_STATE_GENERAL,
    RESOURCE_STATE_CONSTANT_BUFFER,
    RESOURCE_STATE_VERTEX_BUFFER,
    RESOURCE_STATE_INDEX_BUFFER,
    RESOURCE_STATE_RENDER_TARGET,
    RESOURCE_STATE_UNORDERED_ACCESS,
    RESOURCE_STATE_DEPTH_STENCIL_READ,        // Depth and stencil READ
    RESOURCE_STATE_DEPTH_STENCIL_WRITE,       // Depth and stencil WRITE
    RESOURCE_STATE_DEPTH_WRITE_STENCIL_READ,  // Depth WRITE and stencil READ
    RESOURCE_STATE_DEPTH_READ_STENCIL_WRITE,  // Depth READ and stencil WRITE
    RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE, // VS, HS, DS, GS, CS
    RESOURCE_STATE_PIXEL_SHADER_RESOURCE,     // PS
    RESOURCE_STATE_SHADER_RESOURCE,           // RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE and RESOURCE_STATE_PIXEL_SHADER_RESOURCE
    RESOURCE_STATE_STREAM_OUT,
    RESOURCE_STATE_INDIRECT_ARGUMENT,
    RESOURCE_STATE_COPY_SRC,
    RESOURCE_STATE_COPY_DST,
    RESOURCE_STATE_RESOLVE_SRC,
    RESOURCE_STATE_RESOLVE_DST,
    RESOURCE_STATE_PRESENT,
    RESOURCE_STATE_PREDICATION,
    RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE,
    RESOURCE_STATE_FRAGMENT_DENSITY_MAP_ATTACHMENT,
    RESOURCE_STATE_FRAGMENT_SHADING_RATE_ATTACHMENT,
};

enum SamplerAddressMode
{
    SAMPLER_ADDRESS_MODE_REPEAT          = 0,
    SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT = 1,
    SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE   = 2,
    SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER = 3,
};

enum SamplerMipmapMode
{
    SAMPLER_MIPMAP_MODE_NEAREST = 0,
    SAMPLER_MIPMAP_MODE_LINEAR  = 1,
};

enum SampleCount
{
    SAMPLE_COUNT_1  = 1,
    SAMPLE_COUNT_2  = 2,
    SAMPLE_COUNT_4  = 4,
    SAMPLE_COUNT_8  = 8,
    SAMPLE_COUNT_16 = 16,
    SAMPLE_COUNT_32 = 32,
    SAMPLE_COUNT_64 = 64,
};

enum SemaphoreType
{
    SEMAPHORE_TYPE_BINARY   = 0,
    SEMAPHORE_TYPE_TIMELINE = 1,
};

enum ShaderStageBits
{
    SHADER_STAGE_UNDEFINED    = 0x00000000,
    SHADER_STAGE_VS           = 0x00000001,
    SHADER_STAGE_HS           = 0x00000002,
    SHADER_STAGE_DS           = 0x00000004,
    SHADER_STAGE_GS           = 0x00000008,
    SHADER_STAGE_PS           = 0x00000010,
    SHADER_STAGE_CS           = 0x00000020,
    SHADER_STAGE_ALL_GRAPHICS = 0x0000001F,
    SHADER_STAGE_ALL          = 0x7FFFFFFF,
};

enum StencilOp
{
    STENCIL_OP_KEEP                = 0,
    STENCIL_OP_ZERO                = 1,
    STENCIL_OP_REPLACE             = 2,
    STENCIL_OP_INCREMENT_AND_CLAMP = 3,
    STENCIL_OP_DECREMENT_AND_CLAMP = 4,
    STENCIL_OP_INVERT              = 5,
    STENCIL_OP_INCREMENT_AND_WRAP  = 6,
    STENCIL_OP_DECREMENT_AND_WRAP  = 7,
};

enum TessellationDomainOrigin
{
    TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT = 0,
    TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT = 1,
};

enum TransitionFlag
{
    TRANSITION_FLAG_API_REQUIRED = 1, // Indicatesa transition that must be executed by the API
    TRANSITION_FALG_API_OPTIONAL = 2, // Idicates a transition that can be optionally ignored by the API
};

enum VendorId
{
    VENDOR_ID_UNKNOWN = 0x0000,
    VENDOR_ID_AMD     = 0x1002,
    VENDOR_ID_INTEL   = 0x8086,
    VENDOR_ID_NVIDIA  = 0x10DE,
};

enum VertexInputRate
{
    VERTEX_INPUT_RATE_VERTEX   = 0,
    VERETX_INPUT_RATE_INSTANCE = 1,
};

enum VertexSemantic
{
    VERTEX_SEMANTIC_UNDEFINED  = 0,
    VERTEX_SEMANTIC_POSITION   = 1, // Object space position
    VERTEX_SEMANTIC_NORMAL     = 2, // Object space normals
    VERTEX_SEMANTIC_COLOR      = 3, // Vertex color
    VERTEX_SEMANTIC_TANGENT    = 4, // Object space tangents
    VERTEX_SEMANTIC_BITANGENT  = 5, // Object space bitangents
    VERTEX_SEMANTIC_TEXCOORD   = 6,
    VERTEX_SEMANTIC_TEXCOORD0  = VERTEX_SEMANTIC_TEXCOORD + 1,
    VERTEX_SEMANTIC_TEXCOORD1  = VERTEX_SEMANTIC_TEXCOORD0 + 1,
    VERTEX_SEMANTIC_TEXCOORD2  = VERTEX_SEMANTIC_TEXCOORD1 + 1,
    VERTEX_SEMANTIC_TEXCOORD3  = VERTEX_SEMANTIC_TEXCOORD2 + 1,
    VERTEX_SEMANTIC_TEXCOORD4  = VERTEX_SEMANTIC_TEXCOORD3 + 1,
    VERTEX_SEMANTIC_TEXCOORD5  = VERTEX_SEMANTIC_TEXCOORD4 + 1,
    VERTEX_SEMANTIC_TEXCOORD6  = VERTEX_SEMANTIC_TEXCOORD5 + 1,
    VERTEX_SEMANTIC_TEXCOORD7  = VERTEX_SEMANTIC_TEXCOORD6 + 1,
    VERTEX_SEMANTIC_TEXCOORD8  = VERTEX_SEMANTIC_TEXCOORD7 + 1,
    VERTEX_SEMANTIC_TEXCOORD9  = VERTEX_SEMANTIC_TEXCOORD8 + 1,
    VERTEX_SEMANTIC_TEXCOORD10 = VERTEX_SEMANTIC_TEXCOORD9 + 1,
    VERTEX_SEMANTIC_TEXCOORD11 = VERTEX_SEMANTIC_TEXCOORD10 + 1,
    VERTEX_SEMANTIC_TEXCOORD12 = VERTEX_SEMANTIC_TEXCOORD11 + 1,
    VERTEX_SEMANTIC_TEXCOORD13 = VERTEX_SEMANTIC_TEXCOORD12 + 1,
    VERTEX_SEMANTIC_TEXCOORD14 = VERTEX_SEMANTIC_TEXCOORD13 + 1,
    VERTEX_SEMANTIC_TEXCOORD15 = VERTEX_SEMANTIC_TEXCOORD14 + 1,
    VERTEX_SEMANTIC_TEXCOORD16 = VERTEX_SEMANTIC_TEXCOORD15 + 1,
    VERTEX_SEMANTIC_TEXCOORD17 = VERTEX_SEMANTIC_TEXCOORD16 + 1,
    VERTEX_SEMANTIC_TEXCOORD18 = VERTEX_SEMANTIC_TEXCOORD17 + 1,
    VERTEX_SEMANTIC_TEXCOORD19 = VERTEX_SEMANTIC_TEXCOORD18 + 1,
    VERTEX_SEMANTIC_TEXCOORD20 = VERTEX_SEMANTIC_TEXCOORD19 + 1,
    VERTEX_SEMANTIC_TEXCOORD21 = VERTEX_SEMANTIC_TEXCOORD20 + 1,
    VERTEX_SEMANTIC_TEXCOORD22 = VERTEX_SEMANTIC_TEXCOORD21 + 1,
};

enum YcbcrModelConversion
{
    // Specifies that the color space for the image is RGB, and
    // should be kept that way without conversion.
    YCBCR_MODEL_CONVERSION_RGB_IDENTITY = 0,
    // Specifies that the color space for the image is YCbCr, and
    // should be range expanded from a compressed format.
    YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY = 1,
    // Specifies that the color model is YCbCr, but should
    // be converted to RGB based on BT.709 for shader operations.
    YCBCR_MODEL_CONVERSION_YCBCR_709 = 2,
    // Specifies that the color model is YCbCr, but should
    // be converted to RGB based on BT.601 for shader operations.
    YCBCR_MODEL_CONVERSION_YCBCR_601 = 3,
    // Specifies that the color mdoel is YCbCr, but should
    // be converted to RGB based on BT.2020 for shader operations.
    YCBCR_MODEL_CONVERSION_YCBCR_2020 = 4,
};

enum YcbcrRange
{
    YCBCR_RANGE_ITU_FULL   = 0,
    YCBCR_RANGE_ITU_NARROW = 1,
};

} // namespace grfx
} // namespace ppx

#endif // ppx_grfx_enums_h
