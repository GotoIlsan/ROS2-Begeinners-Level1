// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from my_robot_interfaces:msg/ListAliveTurtle.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "my_robot_interfaces/msg/detail/list_alive_turtle__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace my_robot_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ListAliveTurtle_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) my_robot_interfaces::msg::ListAliveTurtle(_init);
}

void ListAliveTurtle_fini_function(void * message_memory)
{
  auto typed_message = static_cast<my_robot_interfaces::msg::ListAliveTurtle *>(message_memory);
  typed_message->~ListAliveTurtle();
}

size_t size_function__ListAliveTurtle__names(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ListAliveTurtle__names(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__ListAliveTurtle__names(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__ListAliveTurtle__names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__ListAliveTurtle__names(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__ListAliveTurtle__names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__ListAliveTurtle__names(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__ListAliveTurtle__names(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ListAliveTurtle__x(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ListAliveTurtle__x(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__ListAliveTurtle__x(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__ListAliveTurtle__x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ListAliveTurtle__x(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ListAliveTurtle__x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ListAliveTurtle__x(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__ListAliveTurtle__x(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ListAliveTurtle__y(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ListAliveTurtle__y(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__ListAliveTurtle__y(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__ListAliveTurtle__y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ListAliveTurtle__y(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ListAliveTurtle__y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ListAliveTurtle__y(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__ListAliveTurtle__y(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ListAliveTurtle_message_member_array[3] = {
  {
    "names",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces::msg::ListAliveTurtle, names),  // bytes offset in struct
    nullptr,  // default value
    size_function__ListAliveTurtle__names,  // size() function pointer
    get_const_function__ListAliveTurtle__names,  // get_const(index) function pointer
    get_function__ListAliveTurtle__names,  // get(index) function pointer
    fetch_function__ListAliveTurtle__names,  // fetch(index, &value) function pointer
    assign_function__ListAliveTurtle__names,  // assign(index, value) function pointer
    resize_function__ListAliveTurtle__names  // resize(index) function pointer
  },
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces::msg::ListAliveTurtle, x),  // bytes offset in struct
    nullptr,  // default value
    size_function__ListAliveTurtle__x,  // size() function pointer
    get_const_function__ListAliveTurtle__x,  // get_const(index) function pointer
    get_function__ListAliveTurtle__x,  // get(index) function pointer
    fetch_function__ListAliveTurtle__x,  // fetch(index, &value) function pointer
    assign_function__ListAliveTurtle__x,  // assign(index, value) function pointer
    resize_function__ListAliveTurtle__x  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces::msg::ListAliveTurtle, y),  // bytes offset in struct
    nullptr,  // default value
    size_function__ListAliveTurtle__y,  // size() function pointer
    get_const_function__ListAliveTurtle__y,  // get_const(index) function pointer
    get_function__ListAliveTurtle__y,  // get(index) function pointer
    fetch_function__ListAliveTurtle__y,  // fetch(index, &value) function pointer
    assign_function__ListAliveTurtle__y,  // assign(index, value) function pointer
    resize_function__ListAliveTurtle__y  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ListAliveTurtle_message_members = {
  "my_robot_interfaces::msg",  // message namespace
  "ListAliveTurtle",  // message name
  3,  // number of fields
  sizeof(my_robot_interfaces::msg::ListAliveTurtle),
  ListAliveTurtle_message_member_array,  // message members
  ListAliveTurtle_init_function,  // function to initialize message memory (memory has to be allocated)
  ListAliveTurtle_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ListAliveTurtle_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ListAliveTurtle_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace my_robot_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<my_robot_interfaces::msg::ListAliveTurtle>()
{
  return &::my_robot_interfaces::msg::rosidl_typesupport_introspection_cpp::ListAliveTurtle_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, my_robot_interfaces, msg, ListAliveTurtle)() {
  return &::my_robot_interfaces::msg::rosidl_typesupport_introspection_cpp::ListAliveTurtle_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
