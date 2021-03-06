/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef TENSORFLOW_LITE_TOOLS_OPTIMIZE_OPERATOR_PROPERTY_H_
#define TENSORFLOW_LITE_TOOLS_OPTIMIZE_OPERATOR_PROPERTY_H_

#include "tensorflow/lite/model.h"
#include "tensorflow/lite/schema/schema_generated.h"

namespace tflite {
namespace optimize {
namespace operator_property {

struct OperatorProperty {
  // Per axis.
  bool per_axis;
  // TODO(jianlijianli): remove dimension index and read it from tensor instead.
  int per_axis_index;

  // Op has arbitrary number of inputs, such as concat.
  bool arbitrary_inputs;
  // Input and weight indexes. Unable to separate the two because of ops such as
  // ADD.
  std::vector<int> input_indexes;

  // Output indexes
  std::vector<int> output_indexes;

  // Bias indexes.
  std::vector<int> biases;

  // Constraints.
  bool restrict_same_input_output_scale;
  bool restriction_on_output;
  std::pair<float, float> restricted_value_on_output;
};

TfLiteStatus GetOperatorProperty(const BuiltinOperator& op,
                                 OperatorProperty* property);

}  // namespace operator_property
}  // namespace optimize
}  // namespace tflite

#endif  // TENSORFLOW_LITE_TOOLS_OPTIMIZE_OPERATOR_PROPERTY_H_
