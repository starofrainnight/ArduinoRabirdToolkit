#ifndef __INCLUDED_C140043A425411E6A04700F1F38F93EF
#define __INCLUDED_C140043A425411E6A04700F1F38F93EF

#include <stddef.h>
#include <stdint.h>

namespace Rt
{
template<class T>
struct RTypeSignTraits;

template<>
struct RTypeSignTraits<char>
{
  typedef signed char Signed;
  typedef unsigned char Unsigned;
};

template<>
struct RTypeSignTraits<unsigned char>
{
  typedef signed char Signed;
  typedef unsigned char Unsigned;
};

template<>
struct RTypeSignTraits<short>
{
  typedef signed short Signed;
  typedef unsigned short Unsigned;
};

template<>
struct RTypeSignTraits<unsigned short>
{
  typedef signed short Signed;
  typedef unsigned short Unsigned;
};

template<>
struct RTypeSignTraits<int>
{
  typedef signed int Signed;
  typedef unsigned int Unsigned;
};

template<>
struct RTypeSignTraits<unsigned int>
{
  typedef signed int Signed;
  typedef unsigned int Unsigned;
};

template<>
struct RTypeSignTraits<long>
{
  typedef signed long Signed;
  typedef unsigned long Unsigned;
};

template<>
struct RTypeSignTraits<unsigned long>
{
  typedef signed long Signed;
  typedef unsigned long Unsigned;
};

template<>
struct RTypeSignTraits<long long>
{
  typedef signed long long Signed;
  typedef unsigned long long Unsigned;
};

template<>
struct RTypeSignTraits<unsigned long long>
{
  typedef signed long long Signed;
  typedef unsigned long long Unsigned;
};

}

typedef Rt::RTypeSignTraits<size_t>::Signed rsize_t;

/**
 * A number type use for limited reference counter.
 *
 * It's designed for fewer memory size (equal to the pointer size) and
 * signed type.
 *
 * @brief rnumber_t
 */
typedef Rt::RTypeSignTraits<uintptr_t>::Signed rnumber_t;

template <class Type>
inline
uintptr_t
rShortenPtr(const Type * longPtr)
{
  return static_cast<uintptr_t>(reinterpret_cast<int>(const_cast<Type *>(longPtr)));
}

template <class PtrType>
inline
PtrType
rLengthenPtr(uintptr_t shortPtr)
{
  return reinterpret_cast<PtrType>(static_cast<int>((shortPtr)));
}

/**
 * Calculate how much elements in the array
 *
 * @param array Target array variant to calculate
 */
#define R_SIZE_OF_ARRAY(array) (sizeof((array))/sizeof((array)[0]))

/**
 * Disable copy constructor and assign operations.
 *
 */
#define R_DISABLE_COPY(Class) \
  Class(const Class &); \
  Class &operator=(const Class &);

#endif // __INCLUDED_C140043A425411E6A04700F1F38F93EF
