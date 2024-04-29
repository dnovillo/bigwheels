// Copyright 2024 Google LLC
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
//
// This shader is based on VertexColors.hlsl
// The main addition is we have two matrices in our UB
// and we select which one to use based on view index.

struct TransformData
{
    float4x4 M[2];
};

ConstantBuffer<TransformData> Transform : register(b0);

struct VSOutput
{
    float4 Position : SV_POSITION;
    float3 Color : COLOR;
};

VSOutput vsmain(float4 Position : POSITION, float3 Color : COLOR, uint ViewIndex : SV_ViewID)
{
    VSOutput result;
    result.Position = mul(Transform.M[ViewIndex], Position);
    result.Color = Color;
    return result;
}

float4 psmain(VSOutput input) : SV_TARGET
{
    return float4(input.Color, 1);
}
