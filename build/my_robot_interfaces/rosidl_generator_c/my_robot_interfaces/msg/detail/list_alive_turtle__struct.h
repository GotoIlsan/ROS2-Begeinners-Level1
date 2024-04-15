// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/ListAliveTurtle.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__LIST_ALIVE_TURTLE__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__LIST_ALIVE_TURTLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'names'
#include "rosidl_runtime_c/string.h"
// Member 'x'
// Member 'y'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/ListAliveTurtle in the package my_robot_interfaces.
typedef struct my_robot_interfaces__msg__ListAliveTurtle
{
  rosidl_runtime_c__String__Sequence names;
  rosidl_runtime_c__double__Sequence x;
  rosidl_runtime_c__double__Sequence y;
} my_robot_interfaces__msg__ListAliveTurtle;

// Struct for a sequence of my_robot_interfaces__msg__ListAliveTurtle.
typedef struct my_robot_interfaces__msg__ListAliveTurtle__Sequence
{
  my_robot_interfaces__msg__ListAliveTurtle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__ListAliveTurtle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__LIST_ALIVE_TURTLE__STRUCT_H_
