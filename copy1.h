 * Copyright (c) 1999

 *

 * and its documentation for any purpose is hereby granted without fee,

 * that both that copyright notice and this permission notice appear

 * representations about the suitability of this software for any

 */

#ifndef __CONCEPT_CHECKS_H



  Use these macro like assertions, but they assert properties

  verify whether a type "models" a "concept".

  This set of requirements and the terminology used here is derived

  (Addison Wesley). For further information please consult that

  standard.

  This file covers the basic concepts and the iterator concepts.

  for the STL containers:

    sequence_concepts.h





    - some issues with regards to concept classification and mutability

      and SortedAssociativeContainer -> ReversibleContainer

    - Allocator







// On those compilers we define the concept check macros to do nothing.

#define __STL_CLASS_REQUIRES(__type_var, __concept) \

#define __STL_CONVERTIBLE(__type_x, __type_y) do {} while(0)

#define __STL_CLASS_REQUIRES_SAME_TYPE(__type_x, __type_y) \

#define __STL_GENERATOR_CHECK(__func, __ret) do {} while(0)

  static int  __##__func##__ret##_generator_check

#define __STL_CLASS_UNARY_FUNCTION_CHECK(__func, __ret, __arg) \

#define __STL_BINARY_FUNCTION_CHECK(__func, __ret, __first, __second) \

#define __STL_CLASS_BINARY_FUNCTION_CHECK(__func, __ret, __first, __second) \

#define __STL_REQUIRES_BINARY_OP(__opname, __ret, __first, __second) \

#define __STL_CLASS_REQUIRES_BINARY_OP(__opname, __ret, __first, __second) \





// satisfies the requirements of "__concept".  Here is a list of concepts

//       _Allocator

//       _DefaultConstructible

//       _LessThanComparable

//       _InputIterator

//       _ForwardIterator

//       _RandomAccessIterator

//       _Mutable_ForwardIterator

//       _Mutable_RandomAccessIterator

#define __STL_REQUIRES(__type_var, __concept) \

  void (*__x)( __type_var ) = __concept##_concept_specification< __type_var >\



#define __STL_CONVERTIBLE(__type_x, __type_y) \

  void (*__x)( __type_x , __type_y ) = _STL_CONVERT_ERROR< __type_x , \

  __x = __x; } while (0)

// Use this to test whether two template arguments are the same type

do { \

    __type_y  >::__type_X_not_same_as_type_Y; \



// function object checks

do { \

     _STL_GENERATOR_ERROR< \

  __x = __x; } while (0)



do { \

     _STL_UNARY_FUNCTION_ERROR< \

  __x = __x; } while (0)



do { \

     _STL_BINARY_FUNCTION_ERROR< \

  __x = __x; } while (0)



    do { \

    __ret, __first, __second>::__binary_operator_requirement_violation; \

    _STL_BINARY##__opname##_ERROR< __ret, __first, __second>:: \

  __y = __y; __x = __x; } while (0)





#define __STL_CLASS_REQUIRES_SAME_TYPE(__type_x, __type_y)

#define __STL_CLASS_UNARY_FUNCTION_CHECK(__func, __ret, __arg)

#define __STL_CLASS_REQUIRES_BINARY_OP(__opname, __ret, __first, __second)

#else

// Use this macro inside of template classes, where you would

// Warning: do not pass pointers and such (e.g. T*) in as the __type_var,

// the pointer type, then use the typedef name for the __type_var.

  typedef void (* __func##__type_var##__concept)( __type_var ); \

  struct __dummy_struct_##__type_var##__concept { }; \

    __concept##_concept_specification< \

  __dummy_ptr_##__type_var##__concept



  typedef void (* __func_##__type_x##__type_y##same_type)( __type_x, \

  template < __func_##__type_x##__type_y##same_type _Tp1> \

  static __dummy_struct_##__type_x##__type_y##_same_type< \

  __dummy_ptr_##__type_x##__type_y##_same_type



  typedef __ret (* __f_##__func##__ret##_generator)( __func& ); \

  struct __dummy_struct_##__func##__ret##_generator { }; \

    _STL_GENERATOR_ERROR< \

  __dummy_ptr_##__func##__ret##_generator



  typedef __ret (* __f_##__func##__ret##__arg##_unary_check)( __func&, \

  template <__f_##__func##__ret##__arg##_unary_check _Tp1> \

  static __dummy_struct_##__func##__ret##__arg##_unary_check< \

      __func, __ret, __arg>::__unary_function_requirement_violation>  \



#define __STL_CLASS_BINARY_FUNCTION_CHECK(__func, __ret, __first, __second) \

                                                    const __second& ); \

  struct __dummy_struct_##__func##__ret##__first##__second##_binary_check { }; \

    _STL_BINARY_FUNCTION_ERROR<__func, __ret, __first, __second>:: \

  __dummy_ptr_##__func##__ret##__first##__second##_binary_check



  typedef __ret (* __f_##__func##__ret##__first##__second##_binary_op)(const __first&, \

  template <__f_##__func##__ret##__first##__second##_binary_op _Tp1> \

  static __dummy_struct_##__func##__ret##__first##__second##_binary_op< \

  __binary_operator_requirement_violation>  \





   something to assign to etc. when testing constant iterators. */

template <class _Tp>

  typedef _Tp _Type;

template <class _Tp>

  typedef _Tp _Type;



/* helper function for avoiding compiler warnings about unused variables */

void __sink_unused_warning(_Type) { }

template <class _TypeX, class _TypeY>

  static void

    _TypeY __y = __x;

  }



template <class _Type> struct __check_equal { };

template <class _TypeX, class _TypeY>

  static void

    __check_equal<_TypeX> t1 = __check_equal<_TypeY>();

};





struct _STL_GENERATOR_ERROR {

    return __f();

};

template <class _Func>

  static void __generator_requirement_violation(_Func& __f) {

  }



template <class _Func, class _Ret, class _Arg>

  static _Ret

                                          const _Arg& __arg) {

  }



struct _STL_UNARY_FUNCTION_ERROR<_Func, void, _Arg> {

  __unary_function_requirement_violation(_Func& __f,

    __f(__arg);

};

template <class _Func, class _Ret, class _First, class _Second>

  static _Ret

                                          const _First& __first, 

    return __f(__first, __second);

};

template <class _Func, class _First, class _Second>

  static void

                                          const _First& __first, 

    __f(__first, __second);

};



template <class _Ret, class _First, class _Second> \

  static _Ret \

                                                const _Second& __second) { \

  } \

  __binary_operator_requirement_violation(_First& __first,  \

    return __first _OP __second; \

}

__STL_DEFINE_BINARY_OP_CHECK(==, _OP_EQUAL);

__STL_DEFINE_BINARY_OP_CHECK(<, _OP_LESS_THAN);

__STL_DEFINE_BINARY_OP_CHECK(>, _OP_GREATER_THAN);

__STL_DEFINE_BINARY_OP_CHECK(+, _OP_PLUS);

__STL_DEFINE_BINARY_OP_CHECK(/, _OP_DIVIDE);

__STL_DEFINE_BINARY_OP_CHECK(%, _OP_MOD);





  The presence of this class is just to trick EDG into displaying

  classes, the errors in the functions get reported after

  choice just makes for an eye catching error message :)

struct _STL_ERROR {

  template <class _Type>

  __default_constructor_requirement_violation(_Type) {

  }

  static _Type

    __a = __a;

  }

  static _Type

    _Type __c(__a);

  }

  static _Type

                                                  const _Type& __b) {

    return __c;

  template <class _Type>

  __const_parameter_required_for_assignment_operator(_Type __a, 

    __a = __b;

  }

  static _Type

    if (__a < __b || __a > __b || __a <= __b || __a >= __b) return __a;

  }

  static _Type

    if (__a == __b || __a != __b) return __a;

  }

  static void

    __sink_unused_warning(*__i);

  template <class _Iterator>

  __dereference_operator_and_assignment_requirement_violation(_Iterator __i) {

  }

  static void

    ++__i;

  template <class _Iterator>

  __postincrement_operator_requirement_violation(_Iterator __i) {

  }

  static void

    --__i;

  template <class _Iterator>

  __postdecrement_operator_requirement_violation(_Iterator __i) {

  }

  static void

                                                                _Type __t) {

  }

  static _Iterator

                                                       _Distance __n) {

    return __i;

  template <class _Iterator, class _Distance>

  __iterator_addition_requirement_violation(_Iterator __i, _Distance __n) {

    __i = __n + __i;

  }

  static _Iterator

                                                          _Distance __n) {

    return __i;

  template <class _Iterator, class _Distance>

  __iterator_subtraction_requirement_violation(_Iterator __i, _Distance __n) {

    return __i;

  template <class _Iterator, class _Distance>

  __difference_operator_requirement_violation(_Iterator __i, _Iterator __j,

    __n = __i - __j;

  }

  static _Type

                                                  _Distance __n) {

  }

  static void

                                                      _Type* __t,

    __x[__n] = *__t;







template <class _Iterator> struct iterator_traits;



struct __value_type_type_definition_requirement_violation {

};

template <class _Iter> 

  typedef typename __STD::iterator_traits<_Iter>::difference_type

};

template <class _Iter> 

  typedef typename __STD::iterator_traits<_Iter>::reference reference;



struct __pointer_type_definition_requirement_violation {

};

template <class _Iter> 

  typedef typename __STD::iterator_traits<_Iter>::iterator_category 

};

/* Assignable Requirements */



struct _Assignable_concept_specification {

    _STL_ERROR::__assignment_operator_requirement_violation(__a);

    _STL_ERROR::__const_parameter_required_for_copy_constructor(__a,__a);

  }





template <class _Type>

  static void _DefaultConstructible_requirement_violation(_Type __a) {

  }





struct _EqualityComparable_concept_specification {

    _STL_ERROR::__equality_comparable_requirement_violation(__a, __a);

};

/* LessThanComparable Requirements */

struct _LessThanComparable_concept_specification {

    _STL_ERROR::__less_than_comparable_requirement_violation(__a, __a);

};

/* TrivialIterator Requirements */

template <class _TrivialIterator>

static void

  typedef typename

    value_type __T;

  _Assignable_concept_specification<_TrivialIterator>::

  // Refinement of DefaultConstructible

    _DefaultConstructible_requirement_violation(__i);

  _EqualityComparable_concept_specification<_TrivialIterator>::

  // Valid Expressions

}



struct _Mutable_TrivialIterator_concept_specification {

_Mutable_TrivialIterator_requirement_violation(_TrivialIterator __i) {

    _TrivialIterator_requirement_violation(__i);

  _STL_ERROR::__dereference_operator_and_assignment_requirement_violation(__i);

};

/* InputIterator Requirements */

template <class _InputIterator>

static void

  // Refinement of TrivialIterator

    _TrivialIterator_requirement_violation(__i);

  __difference_type_type_definition_requirement_violation<_InputIterator>();

  __pointer_type_definition_requirement_violation<_InputIterator>();

  // Valid Expressions

  _STL_ERROR::__postincrement_operator_requirement_violation(__i);

};

/* OutputIterator Requirements */

template <class _OutputIterator>

static void

  // Refinement of Assignable

    _Assignable_requirement_violation(__i);

  __iterator_category_type_definition_requirement_violation<_OutputIterator>();

  _STL_ERROR::__dereference_operator_requirement_violation(__i);

  _STL_ERROR::__postincrement_operator_requirement_violation(__i);

    __postincrement_operator_and_assignment_requirement_violation(__i, *__i);

};

/* ForwardIterator Requirements */

template <class _ForwardIterator>

static void

  // Refinement of InputIterator

    _InputIterator_requirement_violation(__i);

};

template <class _ForwardIterator>

static void

  _ForwardIterator_concept_specification<_ForwardIterator>::

  // Refinement of OutputIterator

    _OutputIterator_requirement_violation(__i);

};

/* BidirectionalIterator Requirements */

template <class _BidirectionalIterator>

static void

  // Refinement of ForwardIterator

    _ForwardIterator_requirement_violation(__i);

  _STL_ERROR::__predecrement_operator_requirement_violation(__i);

}



struct _Mutable_BidirectionalIterator_concept_specification {

_Mutable_BidirectionalIterator_requirement_violation(

{

    _BidirectionalIterator_requirement_violation(__i);

  _Mutable_ForwardIterator_concept_specification<_BidirectionalIterator>::

  typedef typename

    _BidirectionalIterator>::value_type __T;

  // Valid Expressions

    __postincrement_operator_and_assignment_requirement_violation(__i,

}





struct _RandomAccessIterator_concept_specification {

_RandomAccessIterator_requirement_violation(_RandAccIter __i) {

  _BidirectionalIterator_concept_specification<_RandAccIter>::

  // Refinement of LessThanComparable

    _LessThanComparable_requirement_violation(__i);

        __value_type_type_definition_requirement_violation<_RandAccIter>

    value_type;

        __difference_type_type_definition_requirement_violation<_RandAccIter>

    _Dist;



  _STL_ERROR::__iterator_addition_assignment_requirement_violation(__i,

  _STL_ERROR::__iterator_addition_requirement_violation(__i,

  _STL_ERROR::

                                                            _MutDist());

                                                           _MutDist());

                                                          _MutDist());

  _STL_ERROR::__element_access_operator_requirement_violation(__i,

                                                              _MutDist());

};

template <class _RandAccIter>

static void

{

    _RandomAccessIterator_requirement_violation(__i);

  _Mutable_BidirectionalIterator_concept_specification<_RandAccIter>::

  typedef typename

        ::value_type

  typedef typename

        ::difference_type



  // Valid Expressions

                  __tmp_ptr, _Dist());

};

#define __STL_TYPEDEF_REQUIREMENT(__REQUIREMENT) \

struct __##__REQUIREMENT##__typedef_requirement_violation { \

}

__STL_TYPEDEF_REQUIREMENT(value_type);

__STL_TYPEDEF_REQUIREMENT(size_type);

__STL_TYPEDEF_REQUIREMENT(const_reference);

__STL_TYPEDEF_REQUIREMENT(const_pointer);



struct _Allocator_concept_specification {

_Allocator_requirement_violation(_Alloc __a) {

  _DefaultConstructible_concept_specification<_Alloc>::

  // Refinement of EqualityComparable

    _EqualityComparable_requirement_violation(__a);

  __value_type__typedef_requirement_violation<_Alloc>();

  __size_type__typedef_requirement_violation<_Alloc>();

  __const_reference__typedef_requirement_violation<_Alloc>();

  __const_pointer__typedef_requirement_violation<_Alloc>();

  //__STL_REQUIRES_SAME_TYPE(typename _Alloc::__STL_TEMPLATE rebind<_Tp>::other,

}







// mode:C++


