// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:srv/AddVariable.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__SRV__DETAIL__ADD_VARIABLE__STRUCT_H_
#define CUSTOM_MSGS__SRV__DETAIL__ADD_VARIABLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/AddVariable in the package custom_msgs.
typedef struct custom_msgs__srv__AddVariable_Request
{
  int64_t a;
  int64_t b;
} custom_msgs__srv__AddVariable_Request;

// Struct for a sequence of custom_msgs__srv__AddVariable_Request.
typedef struct custom_msgs__srv__AddVariable_Request__Sequence
{
  custom_msgs__srv__AddVariable_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__srv__AddVariable_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/AddVariable in the package custom_msgs.
typedef struct custom_msgs__srv__AddVariable_Response
{
  int64_t sum;
} custom_msgs__srv__AddVariable_Response;

// Struct for a sequence of custom_msgs__srv__AddVariable_Response.
typedef struct custom_msgs__srv__AddVariable_Response__Sequence
{
  custom_msgs__srv__AddVariable_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__srv__AddVariable_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__SRV__DETAIL__ADD_VARIABLE__STRUCT_H_
