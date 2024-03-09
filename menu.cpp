

#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif 
#include "Python.h"
#ifndef Py_PYTHON_H
    #error Python headers needed to compile C extensions, please install development version of Python.
#elif PY_VERSION_HEX < 0x02060000 || (0x03000000 <= PY_VERSION_HEX && PY_VERSION_HEX < 0x03030000)
    #error Cython requires Python 2.6+ or Python 3.3+.
#else
#define CYTHON_ABI "0_29_34"
#define CYTHON_HEX_VERSION 0x001D22F0
#define CYTHON_FUTURE_DIVISION 1
#include <stddef.h>
#ifndef offsetof
  #define offsetof(type, member) ( (size_t) & ((type*)0) -> member )
#endif
#if !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
  #ifndef __fastcall
    #define __fastcall
  #endif
#endif
#ifndef DL_IMPORT
  #define DL_IMPORT(t) t
#endif
#ifndef DL_EXPORT
  #define DL_EXPORT(t) t
#endif
#define __PYX_COMMA ,
#ifndef HAVE_LONG_LONG
  #if PY_VERSION_HEX >= 0x02070000
    #define HAVE_LONG_LONG
  #endif
#endif
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#ifndef Py_HUGE_VAL
  #define Py_HUGE_VAL HUGE_VAL
#endif
#ifdef PYPY_VERSION
  #define CYTHON_COMPILING_IN_PYPY 1
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #define CYTHON_COMPILING_IN_NOGIL 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #if PY_VERSION_HEX < 0x03050000
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC 0
  #endif
#elif defined(PYSTON_VERSION)
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 1
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #define CYTHON_COMPILING_IN_NOGIL 0
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_ASYNC_SLOTS
  #define CYTHON_USE_ASYNC_SLOTS 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC 0
  #endif
#elif defined(PY_NOGIL)
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #define CYTHON_COMPILING_IN_NOGIL 1
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #ifndef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT 1
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE 1
  #endif
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#else
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 1
  #define CYTHON_COMPILING_IN_NOGIL 0
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYTYPE_LOOKUP
    #define CYTHON_USE_PYTYPE_LOOKUP 0
  #elif !defined(CYTHON_USE_PYTYPE_LOOKUP)
    #define CYTHON_USE_PYTYPE_LOOKUP 1
  #endif
  #if PY_MAJOR_VERSION < 3
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYLONG_INTERNALS
    #define CYTHON_USE_PYLONG_INTERNALS 0
  #elif !defined(CYTHON_USE_PYLONG_INTERNALS)
    #define CYTHON_USE_PYLONG_INTERNALS (PY_VERSION_HEX < 0x030C00A5)
  #endif
  #ifndef CYTHON_USE_PYLIST_INTERNALS
    #define CYTHON_USE_PYLIST_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #if PY_VERSION_HEX < 0x030300F0 || PY_VERSION_HEX >= 0x030B00A2
    #undef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #elif !defined(CYTHON_USE_UNICODE_WRITER)
    #define CYTHON_USE_UNICODE_WRITER 1
  #endif
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #if PY_VERSION_HEX >= 0x030B00A4
    #undef CYTHON_FAST_THREAD_STATE
    #define CYTHON_FAST_THREAD_STATE 0
  #elif !defined(CYTHON_FAST_THREAD_STATE)
    #define CYTHON_FAST_THREAD_STATE 1
  #endif
  #ifndef CYTHON_FAST_PYCALL
    #define CYTHON_FAST_PYCALL (PY_VERSION_HEX < 0x030A0000)
  #endif
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT (PY_VERSION_HEX >= 0x03050000)
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE (PY_VERSION_HEX >= 0x030400a1)
  #endif
  #ifndef CYTHON_USE_DICT_VERSIONS
    #define CYTHON_USE_DICT_VERSIONS ((PY_VERSION_HEX >= 0x030600B1) && (PY_VERSION_HEX < 0x030C00A5))
  #endif
  #if PY_VERSION_HEX >= 0x030B00A4
    #undef CYTHON_USE_EXC_INFO_STACK
    #define CYTHON_USE_EXC_INFO_STACK 0
  #elif !defined(CYTHON_USE_EXC_INFO_STACK)
    #define CYTHON_USE_EXC_INFO_STACK (PY_VERSION_HEX >= 0x030700A3)
  #endif
  #ifndef CYTHON_UPDATE_DESCRIPTOR_DOC
    #define CYTHON_UPDATE_DESCRIPTOR_DOC 1
  #endif
#endif
#if !defined(CYTHON_FAST_PYCCALL)
#define CYTHON_FAST_PYCCALL  (CYTHON_FAST_PYCALL && PY_VERSION_HEX >= 0x030600B1)
#endif
#if CYTHON_USE_PYLONG_INTERNALS
  #if PY_MAJOR_VERSION < 3
    #include "longintrepr.h"
  #endif
  #undef SHIFT
  #undef BASE
  #undef MASK
  #ifdef SIZEOF_VOID_P
    enum { __pyx_check_sizeof_voidp = 1 / (int)(SIZEOF_VOID_P == sizeof(void*)) };
  #endif
#endif
#ifndef __has_attribute
  #define __has_attribute(x) 0
#endif
#ifndef __has_cpp_attribute
  #define __has_cpp_attribute(x) 0
#endif
#ifndef CYTHON_RESTRICT
  #if defined(__GNUC__)
    #define CYTHON_RESTRICT __restrict__
  #elif defined(_MSC_VER) && _MSC_VER >= 1400
    #define CYTHON_RESTRICT __restrict
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_RESTRICT restrict
  #else
    #define CYTHON_RESTRICT
  #endif
#endif
#ifndef CYTHON_UNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define CYTHON_UNUSED __attribute__ ((__unused__))
#   else
#     define CYTHON_UNUSED
#   endif
# elif defined(__ICC) || (defined(__INTEL_COMPILER) && !defined(_MSC_VER))
#   define CYTHON_UNUSED __attribute__ ((__unused__))
# else
#   define CYTHON_UNUSED
# endif
#endif
#ifndef CYTHON_MAYBE_UNUSED_VAR
#  if defined(__cplusplus)
     template<class T> void CYTHON_MAYBE_UNUSED_VAR( const T& ) { }
#  else
#    define CYTHON_MAYBE_UNUSED_VAR(x) (void)(x)
#  endif
#endif
#ifndef CYTHON_NCP_UNUSED
# if CYTHON_COMPILING_IN_CPYTHON
#  define CYTHON_NCP_UNUSED
# else
#  define CYTHON_NCP_UNUSED CYTHON_UNUSED
# endif
#endif
#define __Pyx_void_to_None(void_result) ((void)(void_result), Py_INCREF(Py_None), Py_None)
#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
           typedef unsigned char     uint8_t;
           typedef unsigned int      uint32_t;
        #else
           typedef unsigned __int8   uint8_t;
           typedef unsigned __int32  uint32_t;
        #endif
    #endif
#else
   #include <stdint.h>
#endif
#ifndef CYTHON_FALLTHROUGH
  #if defined(__cplusplus) && __cplusplus >= 201103L
    #if __has_cpp_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH [[fallthrough]]
    #elif __has_cpp_attribute(clang::fallthrough)
      #define CYTHON_FALLTHROUGH [[clang::fallthrough]]
    #elif __has_cpp_attribute(gnu::fallthrough)
      #define CYTHON_FALLTHROUGH [[gnu::fallthrough]]
    #endif
  #endif
  #ifndef CYTHON_FALLTHROUGH
    #if __has_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH __attribute__((fallthrough))
    #else
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
  #if defined(__clang__ ) && defined(__apple_build_version__)
    #if __apple_build_version__ < 7000000
      #undef  CYTHON_FALLTHROUGH
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
#endif

#ifndef __cplusplus
  #error "Cython files generated with the C++ option must be compiled with a C++ compiler."
#endif
#ifndef CYTHON_INLINE
  #if defined(__clang__)
    #define CYTHON_INLINE __inline__ __attribute__ ((__unused__))
  #else
    #define CYTHON_INLINE inline
  #endif
#endif
template<typename T>
void __Pyx_call_destructor(T& x) {
    x.~T();
}
template<typename T>
class __Pyx_FakeReference {
  public:
    __Pyx_FakeReference() : ptr(NULL) { }
    __Pyx_FakeReference(const T& ref) : ptr(const_cast<T*>(&ref)) { }
    T *operator->() { return ptr; }
    T *operator&() { return ptr; }
    operator T&() { return *ptr; }
    template<typename U> bool operator ==(U other) { return *ptr == other; }
    template<typename U> bool operator !=(U other) { return *ptr != other; }
  private:
    T *ptr;
};

#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX < 0x02070600 && !defined(Py_OptimizeFlag)
  #define Py_OptimizeFlag 0
#endif
#define __PYX_BUILD_PY_SSIZE_T "n"
#define CYTHON_FORMAT_SSIZE_T "z"
#if PY_MAJOR_VERSION < 3
  #define __Pyx_BUILTIN_MODULE_NAME "__builtin__"
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a+k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
  #define __Pyx_DefaultClassType PyClass_Type
#else
  #define __Pyx_BUILTIN_MODULE_NAME "builtins"
  #define __Pyx_DefaultClassType PyType_Type
#if PY_VERSION_HEX >= 0x030B00A1
    static CYTHON_INLINE PyCodeObject* __Pyx_PyCode_New(int a, int k, int l, int s, int f,
                                                    PyObject *code, PyObject *c, PyObject* n, PyObject *v,
                                                    PyObject *fv, PyObject *cell, PyObject* fn,
                                                    PyObject *name, int fline, PyObject *lnos) {
        PyObject *kwds=NULL, *argcount=NULL, *posonlyargcount=NULL, *kwonlyargcount=NULL;
        PyObject *nlocals=NULL, *stacksize=NULL, *flags=NULL, *replace=NULL, *call_result=NULL, *empty=NULL;
        const char *fn_cstr=NULL;
        const char *name_cstr=NULL;
        PyCodeObject* co=NULL;
        PyObject *type, *value, *traceback;
        PyErr_Fetch(&type, &value, &traceback);
        if (!(kwds=PyDict_New())) goto end;
        if (!(argcount=PyLong_FromLong(a))) goto end;
        if (PyDict_SetItemString(kwds, "co_argcount", argcount) != 0) goto end;
        if (!(posonlyargcount=PyLong_FromLong(0))) goto end;
        if (PyDict_SetItemString(kwds, "co_posonlyargcount", posonlyargcount) != 0) goto end;
        if (!(kwonlyargcount=PyLong_FromLong(k))) goto end;
        if (PyDict_SetItemString(kwds, "co_kwonlyargcount", kwonlyargcount) != 0) goto end;
        if (!(nlocals=PyLong_FromLong(l))) goto end;
        if (PyDict_SetItemString(kwds, "co_nlocals", nlocals) != 0) goto end;
        if (!(stacksize=PyLong_FromLong(s))) goto end;
        if (PyDict_SetItemString(kwds, "co_stacksize", stacksize) != 0) goto end;
        if (!(flags=PyLong_FromLong(f))) goto end;
        if (PyDict_SetItemString(kwds, "co_flags", flags) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_code", code) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_consts", c) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_names", n) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_varnames", v) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_freevars", fv) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_cellvars", cell) != 0) goto end;
        if (PyDict_SetItemString(kwds, "co_linetable", lnos) != 0) goto end;
        if (!(fn_cstr=PyUnicode_AsUTF8AndSize(fn, NULL))) goto end;
        if (!(name_cstr=PyUnicode_AsUTF8AndSize(name, NULL))) goto end;
        if (!(co = PyCode_NewEmpty(fn_cstr, name_cstr, fline))) goto end;
        if (!(replace = PyObject_GetAttrString((PyObject*)co, "replace"))) goto cleanup_code_too;
        if (!(empty = PyTuple_New(0))) goto cleanup_code_too; // unfortunately __pyx_empty_tuple isn't available here
        if (!(call_result = PyObject_Call(replace, empty, kwds))) goto cleanup_code_too;
        Py_XDECREF((PyObject*)co);
        co = (PyCodeObject*)call_result;
        call_result = NULL;
        if (0) {
            cleanup_code_too:
            Py_XDECREF((PyObject*)co);
            co = NULL;
        }
        end:
        Py_XDECREF(kwds);
        Py_XDECREF(argcount);
        Py_XDECREF(posonlyargcount);
        Py_XDECREF(kwonlyargcount);
        Py_XDECREF(nlocals);
        Py_XDECREF(stacksize);
        Py_XDECREF(replace);
        Py_XDECREF(call_result);
        Py_XDECREF(empty);
        if (type) {
            PyErr_Restore(type, value, traceback);
        }
        return co;
    }
#else
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#endif
  #define __Pyx_DefaultClassType PyType_Type
#endif
#ifndef Py_TPFLAGS_CHECKTYPES
  #define Py_TPFLAGS_CHECKTYPES 0
#endif
#ifndef Py_TPFLAGS_HAVE_INDEX
  #define Py_TPFLAGS_HAVE_INDEX 0
#endif
#ifndef Py_TPFLAGS_HAVE_NEWBUFFER
  #define Py_TPFLAGS_HAVE_NEWBUFFER 0
#endif
#ifndef Py_TPFLAGS_HAVE_FINALIZE
  #define Py_TPFLAGS_HAVE_FINALIZE 0
#endif
#ifndef METH_STACKLESS
  #define METH_STACKLESS 0
#endif
#if PY_VERSION_HEX <= 0x030700A3 || !defined(METH_FASTCALL)
  #ifndef METH_FASTCALL
     #define METH_FASTCALL 0x80
  #endif
  typedef PyObject *(*__Pyx_PyCFunctionFast) (PyObject *self, PyObject *const *args, Py_ssize_t nargs);
  typedef PyObject *(*__Pyx_PyCFunctionFastWithKeywords) (PyObject *self, PyObject *const *args,
                                                          Py_ssize_t nargs, PyObject *kwnames);
#else
  #define __Pyx_PyCFunctionFast _PyCFunctionFast
  #define __Pyx_PyCFunctionFastWithKeywords _PyCFunctionFastWithKeywords
#endif
#if CYTHON_FAST_PYCCALL
#define __Pyx_PyFastCFunction_Check(func)\
    ((PyCFunction_Check(func) && (METH_FASTCALL == (PyCFunction_GET_FLAGS(func) & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)))))
#else
#define __Pyx_PyFastCFunction_Check(func) 0
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Malloc)
  #define PyObject_Malloc(s)   PyMem_Malloc(s)
  #define PyObject_Free(p)     PyMem_Free(p)
  #define PyObject_Realloc(p)  PyMem_Realloc(p)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030400A1
  #define PyMem_RawMalloc(n)           PyMem_Malloc(n)
  #define PyMem_RawRealloc(p, n)       PyMem_Realloc(p, n)
  #define PyMem_RawFree(p)             PyMem_Free(p)
#endif
#if CYTHON_COMPILING_IN_PYSTON
  #define __Pyx_PyCode_HasFreeVars(co)  PyCode_HasFreeVars(co)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno) PyFrame_SetLineNumber(frame, lineno)
#else
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno)  (frame)->f_lineno = (lineno)
#endif
#if !CYTHON_FAST_THREAD_STATE || PY_VERSION_HEX < 0x02070000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#elif PY_VERSION_HEX >= 0x03060000
  #define __Pyx_PyThreadState_Current _PyThreadState_UncheckedGet()
#elif PY_VERSION_HEX >= 0x03000000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#else
  #define __Pyx_PyThreadState_Current _PyThreadState_Current
#endif
#if PY_VERSION_HEX < 0x030700A2 && !defined(PyThread_tss_create) && !defined(Py_tss_NEEDS_INIT)
#include "pythread.h"
#define Py_tss_NEEDS_INIT 0
typedef int Py_tss_t;
static CYTHON_INLINE int PyThread_tss_create(Py_tss_t *key) {
  *key = PyThread_create_key();
  return 0;
}
static CYTHON_INLINE Py_tss_t * PyThread_tss_alloc(void) {
  Py_tss_t *key = (Py_tss_t *)PyObject_Malloc(sizeof(Py_tss_t));
  *key = Py_tss_NEEDS_INIT;
  return key;
}
static CYTHON_INLINE void PyThread_tss_free(Py_tss_t *key) {
  PyObject_Free(key);
}
static CYTHON_INLINE int PyThread_tss_is_created(Py_tss_t *key) {
  return *key != Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE void PyThread_tss_delete(Py_tss_t *key) {
  PyThread_delete_key(*key);
  *key = Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE int PyThread_tss_set(Py_tss_t *key, void *value) {
  return PyThread_set_key_value(*key, value);
}
static CYTHON_INLINE void * PyThread_tss_get(Py_tss_t *key) {
  return PyThread_get_key_value(*key);
}
#endif
#if CYTHON_COMPILING_IN_CPYTHON || defined(_PyDict_NewPresized)
#define __Pyx_PyDict_NewPresized(n)  ((n <= 8) ? PyDict_New() : _PyDict_NewPresized(n))
#else
#define __Pyx_PyDict_NewPresized(n)  PyDict_New()
#endif
#if PY_MAJOR_VERSION >= 3 || CYTHON_FUTURE_DIVISION
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_TrueDivide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceTrueDivide(x,y)
#else
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_Divide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceDivide(x,y)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1 && CYTHON_USE_UNICODE_INTERNALS
#define __Pyx_PyDict_GetItemStr(dict, name)  _PyDict_GetItem_KnownHash(dict, name, ((PyASCIIObject *) name)->hash)
#else
#define __Pyx_PyDict_GetItemStr(dict, name)  PyDict_GetItem(dict, name)
#endif
#if PY_VERSION_HEX > 0x03030000 && defined(PyUnicode_KIND)
  #define CYTHON_PEP393_ENABLED 1
  #if PY_VERSION_HEX >= 0x030C0000
    #define __Pyx_PyUnicode_READY(op)       (0)
  #else
    #define __Pyx_PyUnicode_READY(op)       (likely(PyUnicode_IS_READY(op)) ?\
                                                0 : _PyUnicode_Ready((PyObject *)(op)))
  #endif
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_LENGTH(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_READ_CHAR(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   PyUnicode_MAX_CHAR_VALUE(u)
  #define __Pyx_PyUnicode_KIND(u)         PyUnicode_KIND(u)
  #define __Pyx_PyUnicode_DATA(u)         PyUnicode_DATA(u)
  #define __Pyx_PyUnicode_READ(k, d, i)   PyUnicode_READ(k, d, i)
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  PyUnicode_WRITE(k, d, i, ch)
  #if PY_VERSION_HEX >= 0x030C0000
    #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_LENGTH(u))
  #else
    #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03090000
    #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : ((PyCompactUnicodeObject *)(u))->wstr_length))
    #else
    #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : PyUnicode_GET_SIZE(u)))
    #endif
  #endif
#else
  #define CYTHON_PEP393_ENABLED 0
  #define PyUnicode_1BYTE_KIND  1
  #define PyUnicode_2BYTE_KIND  2
  #define PyUnicode_4BYTE_KIND  4
  #define __Pyx_PyUnicode_READY(op)       (0)
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_SIZE(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) ((Py_UCS4)(PyUnicode_AS_UNICODE(u)[i]))
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   ((sizeof(Py_UNICODE) == 2) ? 65535 : 1114111)
  #define __Pyx_PyUnicode_KIND(u)         (sizeof(Py_UNICODE))
  #define __Pyx_PyUnicode_DATA(u)         ((void*)PyUnicode_AS_UNICODE(u))
  #define __Pyx_PyUnicode_READ(k, d, i)   ((void)(k), (Py_UCS4)(((Py_UNICODE*)d)[i]))
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  (((void)(k)), ((Py_UNICODE*)d)[i] = ch)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_SIZE(u))
#endif
#if CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyUnicode_Concat(a, b)      PyNumber_Add(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  PyNumber_Add(a, b)
#else
  #define __Pyx_PyUnicode_Concat(a, b)      PyUnicode_Concat(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  ((unlikely((a) == Py_None) || unlikely((b) == Py_None)) ?\
      PyNumber_Add(a, b) : __Pyx_PyUnicode_Concat(a, b))
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyUnicode_Contains)
  #define PyUnicode_Contains(u, s)  PySequence_Contains(u, s)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyByteArray_Check)
  #define PyByteArray_Check(obj)  PyObject_TypeCheck(obj, &PyByteArray_Type)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Format)
  #define PyObject_Format(obj, fmt)  PyObject_CallMethod(obj, "__format__", "O", fmt)
#endif
#define __Pyx_PyString_FormatSafe(a, b)   ((unlikely((a) == Py_None || (PyString_Check(b) && !PyString_CheckExact(b)))) ? PyNumber_Remainder(a, b) : __Pyx_PyString_Format(a, b))
#define __Pyx_PyUnicode_FormatSafe(a, b)  ((unlikely((a) == Py_None || (PyUnicode_Check(b) && !PyUnicode_CheckExact(b)))) ? PyNumber_Remainder(a, b) : PyUnicode_Format(a, b))
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyString_Format(a, b)  PyUnicode_Format(a, b)
#else
  #define __Pyx_PyString_Format(a, b)  PyString_Format(a, b)
#endif
#if PY_MAJOR_VERSION < 3 && !defined(PyObject_ASCII)
  #define PyObject_ASCII(o)            PyObject_Repr(o)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBaseString_Type            PyUnicode_Type
  #define PyStringObject               PyUnicodeObject
  #define PyString_Type                PyUnicode_Type
  #define PyString_Check               PyUnicode_Check
  #define PyString_CheckExact          PyUnicode_CheckExact
#ifndef PyObject_Unicode
  #define PyObject_Unicode             PyObject_Str
#endif
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyBaseString_Check(obj) PyUnicode_Check(obj)
  #define __Pyx_PyBaseString_CheckExact(obj) PyUnicode_CheckExact(obj)
#else
  #define __Pyx_PyBaseString_Check(obj) (PyString_Check(obj) || PyUnicode_Check(obj))
  #define __Pyx_PyBaseString_CheckExact(obj) (PyString_CheckExact(obj) || PyUnicode_CheckExact(obj))
#endif
#ifndef PySet_CheckExact
  #define PySet_CheckExact(obj)        (Py_TYPE(obj) == &PySet_Type)
#endif
#if PY_VERSION_HEX >= 0x030900A4
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_SET_REFCNT(obj, refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SET_SIZE(obj, size)
#else
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_REFCNT(obj) = (refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SIZE(obj) = (size)
#endif
#if CYTHON_ASSUME_SAFE_MACROS
  #define __Pyx_PySequence_SIZE(seq)  Py_SIZE(seq)
#else
  #define __Pyx_PySequence_SIZE(seq)  PySequence_Size(seq)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyIntObject                  PyLongObject
  #define PyInt_Type                   PyLong_Type
  #define PyInt_Check(op)              PyLong_Check(op)
  #define PyInt_CheckExact(op)         PyLong_CheckExact(op)
  #define PyInt_FromString             PyLong_FromString
  #define PyInt_FromUnicode            PyLong_FromUnicode
  #define PyInt_FromLong               PyLong_FromLong
  #define PyInt_FromSize_t             PyLong_FromSize_t
  #define PyInt_FromSsize_t            PyLong_FromSsize_t
  #define PyInt_AsLong                 PyLong_AsLong
  #define PyInt_AS_LONG                PyLong_AS_LONG
  #define PyInt_AsSsize_t              PyLong_AsSsize_t
  #define PyInt_AsUnsignedLongMask     PyLong_AsUnsignedLongMask
  #define PyInt_AsUnsignedLongLongMask PyLong_AsUnsignedLongLongMask
  #define PyNumber_Int                 PyNumber_Long
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBoolObject                 PyLongObject
#endif
#if PY_MAJOR_VERSION >= 3 && CYTHON_COMPILING_IN_PYPY
  #ifndef PyUnicode_InternFromString
    #define PyUnicode_InternFromString(s) PyUnicode_FromString(s)
  #endif
#endif
#if PY_VERSION_HEX < 0x030200A4
  typedef long Py_hash_t;
  #define __Pyx_PyInt_FromHash_t PyInt_FromLong
  #define __Pyx_PyInt_AsHash_t   __Pyx_PyIndex_AsHash_t
#else
  #define __Pyx_PyInt_FromHash_t PyInt_FromSsize_t
  #define __Pyx_PyInt_AsHash_t   __Pyx_PyIndex_AsSsize_t
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyMethod_New(func, self, klass) ((self) ? ((void)(klass), PyMethod_New(func, self)) : __Pyx_NewRef(func))
#else
  #define __Pyx_PyMethod_New(func, self, klass) PyMethod_New(func, self, klass)
#endif
#if CYTHON_USE_ASYNC_SLOTS
  #if PY_VERSION_HEX >= 0x030500B1
    #define __Pyx_PyAsyncMethodsStruct PyAsyncMethods
    #define __Pyx_PyType_AsAsync(obj) (Py_TYPE(obj)->tp_as_async)
  #else
    #define __Pyx_PyType_AsAsync(obj) ((__Pyx_PyAsyncMethodsStruct*) (Py_TYPE(obj)->tp_reserved))
  #endif
#else
  #define __Pyx_PyType_AsAsync(obj) NULL
#endif
#ifndef __Pyx_PyAsyncMethodsStruct
    typedef struct {
        unaryfunc am_await;
        unaryfunc am_aiter;
        unaryfunc am_anext;
    } __Pyx_PyAsyncMethodsStruct;
#endif

#if defined(_WIN32) || defined(WIN32) || defined(MS_WINDOWS)
  #if !defined(_USE_MATH_DEFINES)
    #define _USE_MATH_DEFINES
  #endif
#endif
#include <math.h>
#ifdef NAN
#define __PYX_NAN() ((float) NAN)
#else
static CYTHON_INLINE float __PYX_NAN() {
  float value;
  memset(&value, 0xFF, sizeof(value));
  return value;
}
#endif
#if defined(__CYGWIN__) && defined(_LDBL_EQ_DBL)
#define __Pyx_truncl trunc
#else
#define __Pyx_truncl truncl
#endif

#define __PYX_MARK_ERR_POS(f_index, lineno) \
    { __pyx_filename = __pyx_f[f_index]; (void)__pyx_filename; __pyx_lineno = lineno; (void)__pyx_lineno; __pyx_clineno = __LINE__; (void)__pyx_clineno; }
#define __PYX_ERR(f_index, lineno, Ln_error) \
    { __PYX_MARK_ERR_POS(f_index, lineno) goto Ln_error; }

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#define __PYX_HAVE__menu
#define __PYX_HAVE_API__menu

#ifdef _OPENMP
#include <omp.h>
#endif 

#if defined(PYREX_WITHOUT_ASSERTIONS) && !defined(CYTHON_WITHOUT_ASSERTIONS)
#define CYTHON_WITHOUT_ASSERTIONS
#endif

typedef struct {PyObject **p; const char *s; const Py_ssize_t n; const char* encoding;
                const char is_unicode; const char is_str; const char intern; } __Pyx_StringTabEntry;

#define __PYX_DEFAULT_STRING_ENCODING_IS_ASCII 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_UTF8 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT (PY_MAJOR_VERSION >= 3 && __PYX_DEFAULT_STRING_ENCODING_IS_UTF8)
#define __PYX_DEFAULT_STRING_ENCODING ""
#define __Pyx_PyObject_FromString __Pyx_PyBytes_FromString
#define __Pyx_PyObject_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#define __Pyx_uchar_cast(c) ((unsigned char)c)
#define __Pyx_long_cast(x) ((long)x)
#define __Pyx_fits_Py_ssize_t(v, type, is_signed)  (\
    (sizeof(type) < sizeof(Py_ssize_t))  ||\
    (sizeof(type) > sizeof(Py_ssize_t) &&\
          likely(v < (type)PY_SSIZE_T_MAX ||\
                 v == (type)PY_SSIZE_T_MAX)  &&\
          (!is_signed || likely(v > (type)PY_SSIZE_T_MIN ||\
                                v == (type)PY_SSIZE_T_MIN)))  ||\
    (sizeof(type) == sizeof(Py_ssize_t) &&\
          (is_signed || likely(v < (type)PY_SSIZE_T_MAX ||\
                               v == (type)PY_SSIZE_T_MAX)))  )
static CYTHON_INLINE int __Pyx_is_valid_index(Py_ssize_t i, Py_ssize_t limit) {
    return (size_t) i < (size_t) limit;
}
#if defined (__cplusplus) && __cplusplus >= 201103L
    #include <cstdlib>
    #define __Pyx_sst_abs(value) std::abs(value)
#elif SIZEOF_INT >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) abs(value)
#elif SIZEOF_LONG >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) labs(value)
#elif defined (_MSC_VER)
    #define __Pyx_sst_abs(value) ((Py_ssize_t)_abs64(value))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define __Pyx_sst_abs(value) llabs(value)
#elif defined (__GNUC__)
    #define __Pyx_sst_abs(value) __builtin_llabs(value)
#else
    #define __Pyx_sst_abs(value) ((value<0) ? -value : value)
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject*);
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject*, Py_ssize_t* length);
#define __Pyx_PyByteArray_FromString(s) PyByteArray_FromStringAndSize((const char*)s, strlen((const char*)s))
#define __Pyx_PyByteArray_FromStringAndSize(s, l) PyByteArray_FromStringAndSize((const char*)s, l)
#define __Pyx_PyBytes_FromString        PyBytes_FromString
#define __Pyx_PyBytes_FromStringAndSize PyBytes_FromStringAndSize
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char*);
#if PY_MAJOR_VERSION < 3
    #define __Pyx_PyStr_FromString        __Pyx_PyBytes_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#else
    #define __Pyx_PyStr_FromString        __Pyx_PyUnicode_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyUnicode_FromStringAndSize
#endif
#define __Pyx_PyBytes_AsWritableString(s)     ((char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableSString(s)    ((signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableUString(s)    ((unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsString(s)     ((const char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsSString(s)    ((const signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsUString(s)    ((const unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyObject_AsWritableString(s)    ((char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableSString(s)    ((signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableUString(s)    ((unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsSString(s)    ((const signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsUString(s)    ((const unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_FromCString(s)  __Pyx_PyObject_FromString((const char*)s)
#define __Pyx_PyBytes_FromCString(s)   __Pyx_PyBytes_FromString((const char*)s)
#define __Pyx_PyByteArray_FromCString(s)   __Pyx_PyByteArray_FromString((const char*)s)
#define __Pyx_PyStr_FromCString(s)     __Pyx_PyStr_FromString((const char*)s)
#define __Pyx_PyUnicode_FromCString(s) __Pyx_PyUnicode_FromString((const char*)s)
static CYTHON_INLINE size_t __Pyx_Py_UNICODE_strlen(const Py_UNICODE *u) {
    const Py_UNICODE *u_end = u;
    while (*u_end++) ;
    return (size_t)(u_end - u - 1);
}
#define __Pyx_PyUnicode_FromUnicode(u)       PyUnicode_FromUnicode(u, __Pyx_Py_UNICODE_strlen(u))
#define __Pyx_PyUnicode_FromUnicodeAndLength PyUnicode_FromUnicode
#define __Pyx_PyUnicode_AsUnicode            PyUnicode_AsUnicode
#define __Pyx_NewRef(obj) (Py_INCREF(obj), obj)
#define __Pyx_Owned_Py_None(b) __Pyx_NewRef(Py_None)
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b);
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject*);
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x);
#define __Pyx_PySequence_Tuple(obj)\
    (likely(PyTuple_CheckExact(obj)) ? __Pyx_NewRef(obj) : PySequence_Tuple(obj))
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject*);
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t);
static CYTHON_INLINE Py_hash_t __Pyx_PyIndex_AsHash_t(PyObject*);
#if CYTHON_ASSUME_SAFE_MACROS
#define __pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))
#else
#define __pyx_PyFloat_AsDouble(x) PyFloat_AsDouble(x)
#endif
#define __pyx_PyFloat_AsFloat(x) ((float) __pyx_PyFloat_AsDouble(x))
#if PY_MAJOR_VERSION >= 3
#define __Pyx_PyNumber_Int(x) (PyLong_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Long(x))
#else
#define __Pyx_PyNumber_Int(x) (PyInt_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Int(x))
#endif
#define __Pyx_PyNumber_Float(x) (PyFloat_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Float(x))
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
static int __Pyx_sys_getdefaultencoding_not_ascii;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    PyObject* ascii_chars_u = NULL;
    PyObject* ascii_chars_b = NULL;
    const char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    if (strcmp(default_encoding_c, "ascii") == 0) {
        __Pyx_sys_getdefaultencoding_not_ascii = 0;
    } else {
        char ascii_chars[128];
        int c;
        for (c = 0; c < 128; c++) {
            ascii_chars[c] = c;
        }
        __Pyx_sys_getdefaultencoding_not_ascii = 1;
        ascii_chars_u = PyUnicode_DecodeASCII(ascii_chars, 128, NULL);
        if (!ascii_chars_u) goto bad;
        ascii_chars_b = PyUnicode_AsEncodedString(ascii_chars_u, default_encoding_c, NULL);
        if (!ascii_chars_b || !PyBytes_Check(ascii_chars_b) || memcmp(ascii_chars, PyBytes_AS_STRING(ascii_chars_b), 128) != 0) {
            PyErr_Format(
                PyExc_ValueError,
                "This module compiled with c_string_encoding=ascii, but default encoding '%.200s' is not a superset of ascii.",
                default_encoding_c);
            goto bad;
        }
        Py_DECREF(ascii_chars_u);
        Py_DECREF(ascii_chars_b);
    }
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    Py_XDECREF(ascii_chars_u);
    Py_XDECREF(ascii_chars_b);
    return -1;
}
#endif
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT && PY_MAJOR_VERSION >= 3
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_DecodeUTF8(c_str, size, NULL)
#else
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_Decode(c_str, size, __PYX_DEFAULT_STRING_ENCODING, NULL)
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
static char* __PYX_DEFAULT_STRING_ENCODING;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) (const char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    __PYX_DEFAULT_STRING_ENCODING = (char*) malloc(strlen(default_encoding_c) + 1);
    if (!__PYX_DEFAULT_STRING_ENCODING) goto bad;
    strcpy(__PYX_DEFAULT_STRING_ENCODING, default_encoding_c);
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    return -1;
}
#endif
#endif



#if defined(__GNUC__)     && (__GNUC__ > 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)))
  #define likely(x)   __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
#else 
  #define likely(x)   (x)
  #define unlikely(x) (x)
#endif 
static CYTHON_INLINE void __Pyx_pretend_to_initialize(void* ptr) { (void)ptr; }

static PyObject *__pyx_m = NULL;
static PyObject *__pyx_d;
static PyObject *__pyx_b;
static PyObject *__pyx_cython_runtime = NULL;
static PyObject *__pyx_empty_tuple;
static PyObject *__pyx_empty_bytes;
static PyObject *__pyx_empty_unicode;
static int __pyx_lineno;
static int __pyx_clineno = 0;
static const char * __pyx_cfilenm= __FILE__;
static const char *__pyx_filename;


static const char *__pyx_f[] = {
  "menu.py",
};


struct __pyx_obj_4menu___pyx_scope_struct__ua_api;
struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr;
struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios;
struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr;
struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr;
struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr;
struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr;
struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr;
struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr;
struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr;
struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr;
struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr;


struct __pyx_obj_4menu___pyx_scope_struct__ua_api {
  PyObject_HEAD
  PyObject *__pyx_v_rc;
};



struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4menu___pyx_scope_struct__ua_api *__pyx_outer_scope;
  long __pyx_v_z;
  long __pyx_t_0;
};



struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios {
  PyObject_HEAD
  PyObject *__pyx_v_iphone;
  PyObject *__pyx_v_rc;
};



struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *__pyx_outer_scope;
  long __pyx_v_z;
  long __pyx_t_0;
};



struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *__pyx_outer_scope;
  PyObject *__pyx_v_x;
  PyObject *__pyx_t_0;
  Py_ssize_t __pyx_t_1;
};

struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *__pyx_outer_scope;
  PyObject *__pyx_v_x;
  PyObject *__pyx_t_0;
  Py_ssize_t __pyx_t_1;
};



struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *__pyx_outer_scope;
  PyObject *__pyx_v_x;
  PyObject *__pyx_t_0;
  Py_ssize_t __pyx_t_1;
};

struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *__pyx_outer_scope;
  PyObject *__pyx_v_x;
  PyObject *__pyx_t_0;
  Py_ssize_t __pyx_t_1;
};



struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *__pyx_outer_scope;
  PyObject *__pyx_v_x;
  PyObject *__pyx_t_0;
  Py_ssize_t __pyx_t_1;
};

struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *__pyx_outer_scope;
  PyObject *__pyx_v_x;
  PyObject *__pyx_t_0;
  Py_ssize_t __pyx_t_1;
};



struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *__pyx_outer_scope;
  PyObject *__pyx_v_x;
  PyObject *__pyx_t_0;
  Py_ssize_t __pyx_t_1;
};

struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr {
  PyObject_HEAD
  struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *__pyx_outer_scope;
  PyObject *__pyx_v_x;
  PyObject *__pyx_t_0;
  Py_ssize_t __pyx_t_1;
};




#ifndef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
#endif
#if CYTHON_REFNANNY
  typedef struct {
    void (*INCREF)(void*, PyObject*, int);
    void (*DECREF)(void*, PyObject*, int);
    void (*GOTREF)(void*, PyObject*, int);
    void (*GIVEREF)(void*, PyObject*, int);
    void* (*SetupContext)(const char*, int, const char*);
    void (*FinishContext)(void**);
  } __Pyx_RefNannyAPIStruct;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNanny = NULL;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname);
  #define __Pyx_RefNannyDeclarations void *__pyx_refnanny = NULL;
#ifdef WITH_THREAD
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          if (acquire_gil) {\
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure();\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
              PyGILState_Release(__pyx_gilstate_save);\
          } else {\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
          }
#else
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__)
#endif
  #define __Pyx_RefNannyFinishContext()\
          __Pyx_RefNanny->FinishContext(&__pyx_refnanny)
  #define __Pyx_INCREF(r)  __Pyx_RefNanny->INCREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_DECREF(r)  __Pyx_RefNanny->DECREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GOTREF(r)  __Pyx_RefNanny->GOTREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GIVEREF(r) __Pyx_RefNanny->GIVEREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_XINCREF(r)  do { if((r) != NULL) {__Pyx_INCREF(r); }} while(0)
  #define __Pyx_XDECREF(r)  do { if((r) != NULL) {__Pyx_DECREF(r); }} while(0)
  #define __Pyx_XGOTREF(r)  do { if((r) != NULL) {__Pyx_GOTREF(r); }} while(0)
  #define __Pyx_XGIVEREF(r) do { if((r) != NULL) {__Pyx_GIVEREF(r);}} while(0)
#else
  #define __Pyx_RefNannyDeclarations
  #define __Pyx_RefNannySetupContext(name, acquire_gil)
  #define __Pyx_RefNannyFinishContext()
  #define __Pyx_INCREF(r) Py_INCREF(r)
  #define __Pyx_DECREF(r) Py_DECREF(r)
  #define __Pyx_GOTREF(r)
  #define __Pyx_GIVEREF(r)
  #define __Pyx_XINCREF(r) Py_XINCREF(r)
  #define __Pyx_XDECREF(r) Py_XDECREF(r)
  #define __Pyx_XGOTREF(r)
  #define __Pyx_XGIVEREF(r)
#endif
#define __Pyx_XDECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_XDECREF(tmp);\
    } while (0)
#define __Pyx_DECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_DECREF(tmp);\
    } while (0)
#define __Pyx_CLEAR(r)    do { PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);} while(0)
#define __Pyx_XCLEAR(r)   do { if((r) != NULL) {PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);}} while(0)


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GetAttrStr(o,n) PyObject_GetAttr(o,n)
#endif


static PyObject *__Pyx_GetBuiltinName(PyObject *name);


#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
#define __PYX_DICT_VERSION_INIT  ((PY_UINT64_T) -1)
#define __PYX_GET_DICT_VERSION(dict)  (((PyDictObject*)(dict))->ma_version_tag)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)\
    (version_var) = __PYX_GET_DICT_VERSION(dict);\
    (cache_var) = (value);
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP) {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    if (likely(__PYX_GET_DICT_VERSION(DICT) == __pyx_dict_version)) {\
        (VAR) = __pyx_dict_cached_value;\
    } else {\
        (VAR) = __pyx_dict_cached_value = (LOOKUP);\
        __pyx_dict_version = __PYX_GET_DICT_VERSION(DICT);\
    }\
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj);
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj);
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version);
#else
#define __PYX_GET_DICT_VERSION(dict)  (0)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP)  (VAR) = (LOOKUP);
#endif


#if CYTHON_USE_DICT_VERSIONS
#define __Pyx_GetModuleGlobalName(var, name)  do {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    (var) = (likely(__pyx_dict_version == __PYX_GET_DICT_VERSION(__pyx_d))) ?\
        (likely(__pyx_dict_cached_value) ? __Pyx_NewRef(__pyx_dict_cached_value) : __Pyx_GetBuiltinName(name)) :\
        __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
} while(0)
#define __Pyx_GetModuleGlobalNameUncached(var, name)  do {\
    PY_UINT64_T __pyx_dict_version;\
    PyObject *__pyx_dict_cached_value;\
    (var) = __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
} while(0)
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value);
#else
#define __Pyx_GetModuleGlobalName(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
#define __Pyx_GetModuleGlobalNameUncached(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name);
#endif


#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject *__Pyx_PyCFunction_FastCall(PyObject *func, PyObject **args, Py_ssize_t nargs);
#else
#define __Pyx_PyCFunction_FastCall(func, args, nargs)  (assert(0), NULL)
#endif


#if CYTHON_FAST_PYCALL
#define __Pyx_PyFunction_FastCall(func, args, nargs)\
    __Pyx_PyFunction_FastCallDict((func), (args), (nargs), NULL)
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs);
#else
#define __Pyx_PyFunction_FastCallDict(func, args, nargs, kwargs) _PyFunction_FastCallDict(func, args, nargs, kwargs)
#endif
#define __Pyx_BUILD_ASSERT_EXPR(cond)\
    (sizeof(char [1 - 2*!(cond)]) - 1)
#ifndef Py_MEMBER_SIZE
#define Py_MEMBER_SIZE(type, member) sizeof(((type *)0)->member)
#endif
#if CYTHON_FAST_PYCALL
  static size_t __pyx_pyframe_localsplus_offset = 0;
  #include "frameobject.h"
#if PY_VERSION_HEX >= 0x030b00a6
  #ifndef Py_BUILD_CORE
    #define Py_BUILD_CORE 1
  #endif
  #include "internal/pycore_frame.h"
#endif
  #define __Pxy_PyFrame_Initialize_Offsets()\
    ((void)__Pyx_BUILD_ASSERT_EXPR(sizeof(PyFrameObject) == offsetof(PyFrameObject, f_localsplus) + Py_MEMBER_SIZE(PyFrameObject, f_localsplus)),\
     (void)(__pyx_pyframe_localsplus_offset = ((size_t)PyFrame_Type.tp_basicsize) - Py_MEMBER_SIZE(PyFrameObject, f_localsplus)))
  #define __Pyx_PyFrame_GetLocalsplus(frame)\
    (assert(__pyx_pyframe_localsplus_offset), (PyObject **)(((char *)(frame)) + __pyx_pyframe_localsplus_offset))
#endif // CYTHON_FAST_PYCALL
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw);
#else
#define __Pyx_PyObject_Call(func, arg, kw) PyObject_Call(func, arg, kw)
#endif


static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2);


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg);
#endif


static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg);


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func);
#else
#define __Pyx_PyObject_CallNoArg(func) __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL)
#endif


#if CYTHON_COMPILING_IN_PYPY
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        PyObject_Format(s, f))
#elif PY_MAJOR_VERSION < 3
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        likely(PyString_CheckExact(s)) ? PyUnicode_FromEncodedObject(s, NULL, "strict") :\
        PyObject_Format(s, f))
#elif CYTHON_USE_TYPE_SLOTS
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        likely(PyLong_CheckExact(s)) ? PyLong_Type.tp_str(s) :\
        likely(PyFloat_CheckExact(s)) ? PyFloat_Type.tp_str(s) :\
        PyObject_Format(s, f))
#else
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        PyObject_Format(s, f))
#endif


#include <string.h>


static PyObject* __Pyx_PyUnicode_Join(PyObject* value_tuple, Py_ssize_t value_count, Py_ssize_t result_ulength,
                                      Py_UCS4 max_char);


static CYTHON_INLINE void __Pyx_RaiseClosureNameError(const char *varname);


#if PY_MAJOR_VERSION < 3
#define __Pyx_PyString_Join __Pyx_PyBytes_Join
#define __Pyx_PyBaseString_Join(s, v) (PyUnicode_CheckExact(s) ? PyUnicode_Join(s, v) : __Pyx_PyBytes_Join(s, v))
#else
#define __Pyx_PyString_Join PyUnicode_Join
#define __Pyx_PyBaseString_Join PyUnicode_Join
#endif
#if CYTHON_COMPILING_IN_CPYTHON
    #if PY_MAJOR_VERSION < 3
    #define __Pyx_PyBytes_Join _PyString_Join
    #else
    #define __Pyx_PyBytes_Join _PyBytes_Join
    #endif
#else
static CYTHON_INLINE PyObject* __Pyx_PyBytes_Join(PyObject* sep, PyObject* values);
#endif


#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key);
#define __Pyx_PyObject_Dict_GetItem(obj, name)\
    (likely(PyDict_CheckExact(obj)) ?\
     __Pyx_PyDict_GetItem(obj, name) : PyObject_GetItem(obj, name))
#else
#define __Pyx_PyDict_GetItem(d, key) PyObject_GetItem(d, key)
#define __Pyx_PyObject_Dict_GetItem(obj, name)  PyObject_GetItem(obj, name)
#endif


#define __Pyx_GetItemInt(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Fast(o, (Py_ssize_t)i, is_list, wraparound, boundscheck) :\
    (is_list ? (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL) :\
               __Pyx_GetItemInt_Generic(o, to_py_func(i))))
#define __Pyx_GetItemInt_List(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_List_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
#define __Pyx_GetItemInt_Tuple(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Tuple_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "tuple index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j);
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i,
                                                     int is_list, int wraparound, int boundscheck);


static CYTHON_INLINE int __Pyx_PySequence_ContainsTF(PyObject* item, PyObject* seq, int eq) {
    int result = PySequence_Contains(seq, item);
    return unlikely(result < 0) ? result : (result == (eq == Py_EQ));
}


#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GenericGetAttrNoDict PyObject_GenericGetAttr
#endif


static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level);


static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type);


#define __Pyx_CyFunction_USED 1
#define __Pyx_CYFUNCTION_STATICMETHOD  0x01
#define __Pyx_CYFUNCTION_CLASSMETHOD   0x02
#define __Pyx_CYFUNCTION_CCLASS        0x04
#define __Pyx_CyFunction_GetClosure(f)\
    (((__pyx_CyFunctionObject *) (f))->func_closure)
#define __Pyx_CyFunction_GetClassObj(f)\
    (((__pyx_CyFunctionObject *) (f))->func_classobj)
#define __Pyx_CyFunction_Defaults(type, f)\
    ((type *)(((__pyx_CyFunctionObject *) (f))->defaults))
#define __Pyx_CyFunction_SetDefaultsGetter(f, g)\
    ((__pyx_CyFunctionObject *) (f))->defaults_getter = (g)
typedef struct {
    PyCFunctionObject func;
#if PY_VERSION_HEX < 0x030500A0
    PyObject *func_weakreflist;
#endif
    PyObject *func_dict;
    PyObject *func_name;
    PyObject *func_qualname;
    PyObject *func_doc;
    PyObject *func_globals;
    PyObject *func_code;
    PyObject *func_closure;
    PyObject *func_classobj;
    void *defaults;
    int defaults_pyobjects;
    size_t defaults_size;  // used by FusedFunction for copying defaults
    int flags;
    PyObject *defaults_tuple;
    PyObject *defaults_kwdict;
    PyObject *(*defaults_getter)(PyObject *);
    PyObject *func_annotations;
} __pyx_CyFunctionObject;
static PyTypeObject *__pyx_CyFunctionType = 0;
#define __Pyx_CyFunction_Check(obj)  (__Pyx_TypeCheck(obj, __pyx_CyFunctionType))
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject* op, PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *self,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *m,
                                                         size_t size,
                                                         int pyobjects);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *m,
                                                            PyObject *tuple);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *m,
                                                             PyObject *dict);
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *m,
                                                              PyObject *dict);
static int __pyx_CyFunction_init(void);


static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *closure,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);


#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem * __Pyx_PyErr_GetTopmostException(PyThreadState *tstate);
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyThreadState_declare  PyThreadState *__pyx_tstate;
#define __Pyx_PyThreadState_assign  __pyx_tstate = __Pyx_PyThreadState_Current;
#define __Pyx_PyErr_Occurred()  __pyx_tstate->curexc_type
#else
#define __Pyx_PyThreadState_declare
#define __Pyx_PyThreadState_assign
#define __Pyx_PyErr_Occurred()  PyErr_Occurred()
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSave(type, value, tb)  __Pyx__ExceptionSave(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#define __Pyx_ExceptionReset(type, value, tb)  __Pyx__ExceptionReset(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
#else
#define __Pyx_ExceptionSave(type, value, tb)   PyErr_GetExcInfo(type, value, tb)
#define __Pyx_ExceptionReset(type, value, tb)  PyErr_SetExcInfo(type, value, tb)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_GetException(type, value, tb)  __Pyx__GetException(__pyx_tstate, type, value, tb)
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb);
#endif


#if CYTHON_USE_PYLIST_INTERNALS && CYTHON_ASSUME_SAFE_MACROS
static CYTHON_INLINE int __Pyx_ListComp_Append(PyObject* list, PyObject* x) {
    PyListObject* L = (PyListObject*) list;
    Py_ssize_t len = Py_SIZE(list);
    if (likely(L->allocated > len)) {
        Py_INCREF(x);
        PyList_SET_ITEM(list, len, x);
        __Pyx_SET_SIZE(list, len + 1);
        return 0;
    }
    return PyList_Append(list, x);
}
#else
#define __Pyx_ListComp_Append(L,x) PyList_Append(L,x)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_ExceptionMatches(err) __Pyx_PyErr_ExceptionMatchesInState(__pyx_tstate, err)
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err);
#else
#define __Pyx_PyErr_ExceptionMatches(err)  PyErr_ExceptionMatches(err)
#endif


#if CYTHON_USE_PYLIST_INTERNALS && CYTHON_ASSUME_SAFE_MACROS
static CYTHON_INLINE int __Pyx_PyList_Append(PyObject* list, PyObject* x) {
    PyListObject* L = (PyListObject*) list;
    Py_ssize_t len = Py_SIZE(list);
    if (likely(L->allocated > len) & likely(len > (L->allocated >> 1))) {
        Py_INCREF(x);
        PyList_SET_ITEM(list, len, x);
        __Pyx_SET_SIZE(list, len + 1);
        return 0;
    }
    return PyList_Append(list, x);
}
#else
#define __Pyx_PyList_Append(L,x) PyList_Append(L,x)
#endif


static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method);


static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg);


static CYTHON_INLINE int __Pyx_PyObject_Append(PyObject* L, PyObject* x);


#if CYTHON_USE_TYPE_SLOTS
#define __Pyx_PyObject_DelAttrStr(o,n) __Pyx_PyObject_SetAttrStr(o, n, NULL)
static CYTHON_INLINE int __Pyx_PyObject_SetAttrStr(PyObject* obj, PyObject* attr_name, PyObject* value);
#else
#define __Pyx_PyObject_DelAttrStr(o,n)   PyObject_DelAttr(o,n)
#define __Pyx_PyObject_SetAttrStr(o,n,v) PyObject_SetAttr(o,n,v)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_Clear() __Pyx_ErrRestore(NULL, NULL, NULL)
#define __Pyx_ErrRestoreWithState(type, value, tb)  __Pyx_ErrRestoreInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)    __Pyx_ErrFetchInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  __Pyx_ErrRestoreInState(__pyx_tstate, type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)    __Pyx_ErrFetchInState(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_PyErr_SetNone(exc) (Py_INCREF(exc), __Pyx_ErrRestore((exc), NULL, NULL))
#else
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#endif
#else
#define __Pyx_PyErr_Clear() PyErr_Clear()
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#define __Pyx_ErrRestoreWithState(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestoreInState(tstate, type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchInState(tstate, type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)  PyErr_Fetch(type, value, tb)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSwap(type, value, tb)  __Pyx__ExceptionSwap(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb);
#endif


#ifdef CYTHON_CLINE_IN_TRACEBACK
#define __Pyx_CLineForTraceback(tstate, c_line)  (((CYTHON_CLINE_IN_TRACEBACK)) ? c_line : 0)
#else
static int __Pyx_CLineForTraceback(PyThreadState *tstate, int c_line);
#endif


typedef struct {
    PyCodeObject* code_object;
    int code_line;
} __Pyx_CodeObjectCacheEntry;
struct __Pyx_CodeObjectCache {
    int count;
    int max_count;
    __Pyx_CodeObjectCacheEntry* entries;
};
static struct __Pyx_CodeObjectCache __pyx_code_cache = {0,0,NULL};
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line);
static PyCodeObject *__pyx_find_code_object(int code_line);
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object);


static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename);


#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
#define __Pyx_HAS_GCC_DIAGNOSTIC
#endif


static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value);


static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *);


static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *);


#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_TypeCheck(obj, type) __Pyx_IsSubtype(Py_TYPE(obj), (PyTypeObject *)type)
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject *type);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *type1, PyObject *type2);
#else
#define __Pyx_TypeCheck(obj, type) PyObject_TypeCheck(obj, (PyTypeObject *)type)
#define __Pyx_PyErr_GivenExceptionMatches(err, type) PyErr_GivenExceptionMatches(err, type)
#define __Pyx_PyErr_GivenExceptionMatches2(err, type1, type2) (PyErr_GivenExceptionMatches(err, type1) || PyErr_GivenExceptionMatches(err, type2))
#endif
#define __Pyx_PyException_Check(obj) __Pyx_TypeCheck(obj, PyExc_Exception)


static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause);


typedef PyObject *(*__pyx_coroutine_body_t)(PyObject *, PyThreadState *, PyObject *);
#if CYTHON_USE_EXC_INFO_STACK
#define __Pyx_ExcInfoStruct  _PyErr_StackItem
#else
typedef struct {
    PyObject *exc_type;
    PyObject *exc_value;
    PyObject *exc_traceback;
} __Pyx_ExcInfoStruct;
#endif
typedef struct {
    PyObject_HEAD
    __pyx_coroutine_body_t body;
    PyObject *closure;
    __Pyx_ExcInfoStruct gi_exc_state;
    PyObject *gi_weakreflist;
    PyObject *classobj;
    PyObject *yieldfrom;
    PyObject *gi_name;
    PyObject *gi_qualname;
    PyObject *gi_modulename;
    PyObject *gi_code;
    PyObject *gi_frame;
    int resume_label;
    char is_running;
} __pyx_CoroutineObject;
static __pyx_CoroutineObject *__Pyx__Coroutine_New(
    PyTypeObject *type, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
    PyObject *name, PyObject *qualname, PyObject *module_name);
static __pyx_CoroutineObject *__Pyx__Coroutine_NewInit(
            __pyx_CoroutineObject *gen, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name);
static CYTHON_INLINE void __Pyx_Coroutine_ExceptionClear(__Pyx_ExcInfoStruct *self);
static int __Pyx_Coroutine_clear(PyObject *self);
static PyObject *__Pyx_Coroutine_Send(PyObject *self, PyObject *value);
static PyObject *__Pyx_Coroutine_Close(PyObject *self);
static PyObject *__Pyx_Coroutine_Throw(PyObject *gen, PyObject *args);
#if CYTHON_USE_EXC_INFO_STACK
#define __Pyx_Coroutine_SwapException(self)
#define __Pyx_Coroutine_ResetAndClearException(self)  __Pyx_Coroutine_ExceptionClear(&(self)->gi_exc_state)
#else
#define __Pyx_Coroutine_SwapException(self) {\
    __Pyx_ExceptionSwap(&(self)->gi_exc_state.exc_type, &(self)->gi_exc_state.exc_value, &(self)->gi_exc_state.exc_traceback);\
    __Pyx_Coroutine_ResetFrameBackpointer(&(self)->gi_exc_state);\
    }
#define __Pyx_Coroutine_ResetAndClearException(self) {\
    __Pyx_ExceptionReset((self)->gi_exc_state.exc_type, (self)->gi_exc_state.exc_value, (self)->gi_exc_state.exc_traceback);\
    (self)->gi_exc_state.exc_type = (self)->gi_exc_state.exc_value = (self)->gi_exc_state.exc_traceback = NULL;\
    }
#endif
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyGen_FetchStopIterationValue(pvalue)\
    __Pyx_PyGen__FetchStopIterationValue(__pyx_tstate, pvalue)
#else
#define __Pyx_PyGen_FetchStopIterationValue(pvalue)\
    __Pyx_PyGen__FetchStopIterationValue(__Pyx_PyThreadState_Current, pvalue)
#endif
static int __Pyx_PyGen__FetchStopIterationValue(PyThreadState *tstate, PyObject **pvalue);
static CYTHON_INLINE void __Pyx_Coroutine_ResetFrameBackpointer(__Pyx_ExcInfoStruct *exc_state);


static PyObject* __Pyx_Coroutine_patch_module(PyObject* module, const char* py_code);


static int __Pyx_patch_abc(void);


#define __Pyx_Generator_USED
static PyTypeObject *__pyx_GeneratorType = 0;
#define __Pyx_Generator_CheckExact(obj) (Py_TYPE(obj) == __pyx_GeneratorType)
#define __Pyx_Generator_New(body, code, closure, name, qualname, module_name)\
    __Pyx__Coroutine_New(__pyx_GeneratorType, body, code, closure, name, qualname, module_name)
static PyObject *__Pyx_Generator_Next(PyObject *self);
static int __pyx_Generator_init(void);


static int __Pyx_check_binary_version(void);


static int __Pyx_InitStrings(__Pyx_StringTabEntry *t);



static PyTypeObject *__pyx_ptype_4menu___pyx_scope_struct__ua_api = 0;
static PyTypeObject *__pyx_ptype_4menu___pyx_scope_struct_1_genexpr = 0;
static PyTypeObject *__pyx_ptype_4menu___pyx_scope_struct_2_api_ios = 0;
static PyTypeObject *__pyx_ptype_4menu___pyx_scope_struct_3_genexpr = 0;
static PyTypeObject *__pyx_ptype_4menu___pyx_scope_struct_4_genexpr = 0;
static PyTypeObject *__pyx_ptype_4menu___pyx_scope_struct_5_genexpr = 0;
static PyTypeObject *__pyx_ptype_4menu___pyx_scope_struct_6_genexpr = 0;
static PyTypeObject *__pyx_ptype_4menu___pyx_scope_struct_7_genexpr = 0;
static PyTypeObject *__pyx_ptype_4menu___pyx_scope_struct_8_genexpr = 0;
static PyTypeObject *__pyx_ptype_4menu___pyx_scope_struct_9_genexpr = 0;
static PyTypeObject *__pyx_ptype_4menu___pyx_scope_struct_10_genexpr = 0;
static PyTypeObject *__pyx_ptype_4menu___pyx_scope_struct_11_genexpr = 0;
static PyObject *__pyx_7genexpr__pyx_v_4menu_z;
#define __Pyx_MODULE_NAME "menu"
extern int __pyx_module_is_main_menu;
int __pyx_module_is_main_menu = 0;


static PyObject *__pyx_builtin_print;
static PyObject *__pyx_builtin_range;
static const char __pyx_k_H[] = "H";
static const char __pyx_k_K[] = "K";
static const char __pyx_k_M[] = "M";
static const char __pyx_k_P[] = "P";
static const char __pyx_k_e[] = "e";
static const char __pyx_k_3G[] = "3G";
static const char __pyx_k_4G[] = "4G";
static const char __pyx_k_5G[] = "5G";
static const char __pyx_k_XL[] = "XL";
static const char __pyx_k__4[] = "; ";
static const char __pyx_k__5[] = " ";
static const char __pyx_k__8[] = ",";
static const char __pyx_k__9[] = ":";
static const char __pyx_k_os[] = "os";
static const char __pyx_k_rc[] = "rc";
static const char __pyx_k_re[] = "re";
static const char __pyx_k_rr[] = "rr";
static const char __pyx_k_td[] = "td";
static const char __pyx_k_0_0[] = "{}.0.0.{}.{}";
static const char __pyx_k__11[] = "\n";
static const char __pyx_k__12[] = "";
static const char __pyx_k__14[] = "|";
static const char __pyx_k__21[] = "_";
static const char __pyx_k__23[] = ".";
static const char __pyx_k__30[] = "[";
static const char __pyx_k__31[] = "!";
static const char __pyx_k_bas[] = "bas";
static const char __pyx_k_bs4[] = "bs4";
static const char __pyx_k_get[] = "get";
static const char __pyx_k_ios[] = "ios_";
static const char __pyx_k_ses[] = "ses";
static const char __pyx_k_xyz[] = "xyz";
static const char __pyx_k_AXIS[] = "AXIS";
static const char __pyx_k_OPM1[] = "OPM1";
static const char __pyx_k_PPR1[] = "PPR1";
static const char __pyx_k_QP1A[] = "QP1A";
static const char __pyx_k_RKQ1[] = "RKQ1";
static const char __pyx_k_RP1A[] = "RP1A";
static const char __pyx_k_SKQ1[] = "SKQ1";
static const char __pyx_k_SP1A[] = "SP1A";
static const char __pyx_k_TP1A[] = "TP1A";
static const char __pyx_k_WIFI[] = "WIFI";
static const char __pyx_k_args[] = "args";
static const char __pyx_k_data[] = "data";
static const char __pyx_k_fbcr[] = "fbcr";
static const char __pyx_k_join[] = "join";
static const char __pyx_k_json[] = "json";
static const char __pyx_k_kode[] = "kode";
static const char __pyx_k_link[] = "link";
static const char __pyx_k_main[] = "__main__";
static const char __pyx_k_menu[] = "menu";
static const char __pyx_k_merk[] = "merk";
static const char __pyx_k_name[] = "__name__";
static const char __pyx_k_rozh[] = "rozh";
static const char __pyx_k_send[] = "send";
static const char __pyx_k_test[] = "__test__";
static const char __pyx_k_text[] = "text";
static const char __pyx_k_1_91m[] = "\033[1;91m";
static const char __pyx_k_1_92m[] = "\033[1;92m";
static const char __pyx_k_1_93m[] = "\033[1;93m";
static const char __pyx_k_1_97m[] = "\033[1;97m";
static const char __pyx_k_Build[] = "Build";
static const char __pyx_k_andro[] = "andro";
static const char __pyx_k_ar_AE[] = "ar_AE";
static const char __pyx_k_ar_AR[] = "ar_AR";
static const char __pyx_k_ar_JO[] = "ar_JO";
static const char __pyx_k_ar_SA[] = "ar_SA";
static const char __pyx_k_az_AZ[] = "az_AZ";
static const char __pyx_k_bg_BG[] = "bg_BG";
static const char __pyx_k_bs_BA[] = "bs_BA";
static const char __pyx_k_build[] = "build";
static const char __pyx_k_class[] = "class";
static const char __pyx_k_close[] = "close";
static const char __pyx_k_cs_CZ[] = "cs_CZ";
static const char __pyx_k_de_AT[] = "de_AT";
static const char __pyx_k_de_CH[] = "de_CH";
static const char __pyx_k_de_DE[] = "de_DE";
static const char __pyx_k_el_GR[] = "el_GR";
static const char __pyx_k_en_AU[] = "en_AU";
static const char __pyx_k_en_CA[] = "en_CA";
static const char __pyx_k_en_GB[] = "en_GB";
static const char __pyx_k_en_IE[] = "en_IE";
static const char __pyx_k_en_IN[] = "en_IN";
static const char __pyx_k_en_NZ[] = "en_NZ";
static const char __pyx_k_en_PH[] = "en_PH";
static const char __pyx_k_en_SE[] = "en_SE";
static const char __pyx_k_en_US[] = "en_US";
static const char __pyx_k_en_ZA[] = "en_ZA";
static const char __pyx_k_es_CL[] = "es_CL";
static const char __pyx_k_es_CO[] = "es_CO";
static const char __pyx_k_es_ES[] = "es_ES";
static const char __pyx_k_es_LA[] = "es_LA";
static const char __pyx_k_es_MX[] = "es_MX";
static const char __pyx_k_es_PE[] = "es_PE";
static const char __pyx_k_es_SV[] = "es_SV";
static const char __pyx_k_es_US[] = "es_US";
static const char __pyx_k_fa_IR[] = "fa_IR";
static const char __pyx_k_files[] = "files";
static const char __pyx_k_fr_BE[] = "fr_BE";
static const char __pyx_k_fr_CA[] = "fr_CA";
static const char __pyx_k_fr_CH[] = "fr_CH";
static const char __pyx_k_fr_FR[] = "fr_FR";
static const char __pyx_k_ga_IE[] = "ga_IE";
static const char __pyx_k_hr_HR[] = "hr_HR";
static const char __pyx_k_hu_HU[] = "hu_HU";
static const char __pyx_k_hy_AM[] = "hy_AM";
static const char __pyx_k_in_ID[] = "in_ID";
static const char __pyx_k_it_IT[] = "it_IT";
static const char __pyx_k_it_SM[] = "it_SM";
static const char __pyx_k_iw_IL[] = "iw_IL";
static const char __pyx_k_ka_GE[] = "ka_GE";
static const char __pyx_k_lv_LV[] = "lv_LV";
static const char __pyx_k_nb_NO[] = "nb_NO";
static const char __pyx_k_nl_BE[] = "nl_BE";
static const char __pyx_k_nl_NL[] = "nl_NL";
static const char __pyx_k_pl_PL[] = "pl_PL";
static const char __pyx_k_print[] = "print";
static const char __pyx_k_pt_BR[] = "pt_BR";
static const char __pyx_k_pt_PT[] = "pt_PT";
static const char __pyx_k_range[] = "range";
static const char __pyx_k_ro_RO[] = "ro_RO";
static const char __pyx_k_ru_BY[] = "ru_BY";
static const char __pyx_k_ru_KG[] = "ru_KG";
static const char __pyx_k_ru_KZ[] = "ru_KZ";
static const char __pyx_k_ru_RU[] = "ru_RU";
static const char __pyx_k_ru_UA[] = "ru_UA";
static const char __pyx_k_shell[] = "shell";
static const char __pyx_k_sk_SK[] = "sk_SK";
static const char __pyx_k_sl_SI[] = "sl_SI";
static const char __pyx_k_split[] = "split";
static const char __pyx_k_sr_RS[] = "sr_RS";
static const char __pyx_k_th_TH[] = "th_TH";
static const char __pyx_k_throw[] = "throw";
static const char __pyx_k_tr_TR[] = "tr_TR";
static const char __pyx_k_uk_UA[] = "uk_UA";
static const char __pyx_k_utf_8[] = "utf-8";
static const char __pyx_k_uz_UZ[] = "uz_UZ";
static const char __pyx_k_value[] = "value";
static const char __pyx_k_versi[] = "versi";
static const char __pyx_k_Author[] = "Author";
static const char __pyx_k_Create[] = "Create";
static const char __pyx_k_Github[] = "Github";
static const char __pyx_k_Script[] = "Script";
static const char __pyx_k_Xiaomi[] = "Xiaomi";
static const char __pyx_k_append[] = "append";
static const char __pyx_k_base64[] = "base64";
static const char __pyx_k_choice[] = "choice";
static const char __pyx_k_decode[] = "decode";
static const char __pyx_k_encode[] = "encode";
static const char __pyx_k_extend[] = "extend";
static const char __pyx_k_fb_ori[] = "fb_ori";
static const char __pyx_k_format[] = "format";
static const char __pyx_k_import[] = "__import__";
static const char __pyx_k_iphone[] = "iphone";
static const char __pyx_k_locale[] = "locale";
static const char __pyx_k_parser[] = "parser";
static const char __pyx_k_random[] = "random";
static const char __pyx_k_string[] = "string";
static const char __pyx_k_ua_api[] = "ua_api";
static const char __pyx_k_ua_mes[] = "ua_mes";
static const char __pyx_k_ua_ori[] = "ua_ori";
static const char __pyx_k_ua_web[] = "ua_web";
static const char __pyx_k_xiaomi[] = "xiaomi";
static const char __pyx_k_Build_0[] = "Build/{}.{}.0{}";
static const char __pyx_k_INDOSAT[] = "INDOSAT";
static const char __pyx_k_Indosat[] = "Indosat";
static const char __pyx_k_Session[] = "Session";
static const char __pyx_k_api_ios[] = "api_ios";
static const char __pyx_k_au_asus[] = "au/asus";
static const char __pyx_k_data_ua[] = "data_ua";
static const char __pyx_k_fb_lite[] = "fb_lite";
static const char __pyx_k_findall[] = "findall";
static const char __pyx_k_for_ios[] = "for_ios";
static const char __pyx_k_genexpr[] = "genexpr";
static const char __pyx_k_headers[] = "headers";
static const char __pyx_k_iz_itel[] = "iz/itel";
static const char __pyx_k_list_ua[] = "list_ua";
static const char __pyx_k_menu_py[] = "menu.py";
static const char __pyx_k_mes_ios[] = "mes_ios";
static const char __pyx_k_mes_ori[] = "mes_ori";
static const char __pyx_k_op_oppo[] = "op/oppo";
static const char __pyx_k_randint[] = "randint";
static const char __pyx_k_replace[] = "replace";
static const char __pyx_k_version[] = "version";
static const char __pyx_k_vv_vivo[] = "vv/vivo";
static const char __pyx_k_Babas_XD[] = "Babas XD";
static const char __pyx_k_Facebook[] = "Facebook";
static const char __pyx_k_find_all[] = "find_all";
static const char __pyx_k_mes_kids[] = "mes_kids";
static const char __pyx_k_mes_lite[] = "mes_lite";
static const char __pyx_k_requests[] = "requests";
static const char __pyx_k_tipe_dev[] = "tipe_dev";
static const char __pyx_k_ua_biasa[] = "ua_biasa";
static const char __pyx_k_122_0_0_0[] = "122.0.0.0";
static const char __pyx_k_Telkomsel[] = "Telkomsel";
static const char __pyx_k_XL_Axiata[] = "XL Axiata";
static const char __pyx_k_b16decode[] = "b16decode";
static const char __pyx_k_b16encode[] = "b16encode";
static const char __pyx_k_heker_asu[] = "heker_asu";
static const char __pyx_k_re_realme[] = "re/realme";
static const char __pyx_k_useragent[] = "useragent";
static const char __pyx_k_xi_xiaomi[] = "xi/xiaomi";
static const char __pyx_k_1234567890[] = "1234567890";
static const char __pyx_k_blade_team[] = "blade_team";
static const char __pyx_k_heker_baik[] = "heker_baik";
static const char __pyx_k_if_infinix[] = "if/infinix";
static const char __pyx_k_sa_samsung[] = "sa/samsung";
static const char __pyx_k_subprocess[] = "subprocess";
static const char __pyx_k_user_agent[] = "user-agent";
static const char __pyx_k_html_parser[] = "html.parser";
static const char __pyx_k_check_output[] = "check_output";
static const char __pyx_k_mes_lite_ios[] = "mes_lite_ios";
static const char __pyx_k_versi_chrome[] = "versi_chrome";
static const char __pyx_k_Android_Build[] = "Android .*; (.*?) Build";
static const char __pyx_k_BeautifulSoup[] = "BeautifulSoup";
static const char __pyx_k_Safari_232_65[] = " Safari/232.65";
static const char __pyx_k_Safari_537_36[] = " Safari/537.36";
static const char __pyx_k_01_Oktober_2021[] = "01 Oktober 2021";
static const char __pyx_k_tb_tecno_mobile[] = "tb/tecno-mobile";
static const char __pyx_k_3SinyalKuatHemat[] = "3SinyalKuatHemat";
static const char __pyx_k_Tsel_PakaiMasker[] = "Tsel-PakaiMasker";
static const char __pyx_k_Tsel_PemiluDamai[] = "Tsel-PemiluDamai";
static const char __pyx_k_by_U_PemiluDamai[] = "by.U-PemiluDamai";
static const char __pyx_k_Redmi_Note_10_Pro[] = "Redmi Note 10 Pro";
static const char __pyx_k_cline_in_traceback[] = "cline_in_traceback";
static const char __pyx_k_Mobile_Safari_537_36[] = " Mobile Safari/537.36";
static const char __pyx_k_github_com_RozhBasXYZ[] = "github.com/RozhBasXYZ";
static const char __pyx_k_ua_api_locals_genexpr[] = "ua_api.<locals>.genexpr";
static const char __pyx_k_api_ios_locals_genexpr[] = "api_ios.<locals>.genexpr";
static const char __pyx_k_facebook_com_ROZHBASXY[] = "facebook.com/ROZHBASXY";
static const char __pyx_k_Mozilla_5_0_Linux_Android[] = "Mozilla/5.0 (Linux; Android ";
static const char __pyx_k_Blade_Premium_Facebook_Crack[] = "Blade Premium Facebook Crack";
static const char __pyx_k_getprop_ro_product_cpu_abilist[] = "getprop ro.product.cpu.abilist";
static const char __pyx_k_AppleWebKit_540_77_KHTML_like_G[] = " AppleWebKit/540.77 (KHTML, like Gecko) Chrome/";
static const char __pyx_k_Mozilla_5_0_Macintosh_Intel_Mac[] = "Mozilla/5.0 (Macintosh; Intel Mac OS X ";
static const char __pyx_k_Redmi_Go_Redmi_Note_7_Pro_Redmi[] = "Redmi Go|Redmi Note 7 Pro|Redmi S2|Redmi 1|Redmi 10|Redmi 10 (2022)|Redmi 10 (5G)|Redmi 10 Power|Redmi 10 Prime|Redmi 10 Prime+ (5G)|Redmi 10A|Redmi 10C|Redmi 10X |Redmi 10X LTE|Redmi 10X Pro (5G)|Redmi 11 Prime|Redmi 12|Redmi 12 (5G)|Redmi 12C|Redmi 13C|Redmi 1A|Redmi 1S|Redmi 2|Redmi 20X|Redmi 3|Redmi 3S|Redmi 3X|Redmi 4|Redmi 4 Prime|Redmi 4 Pro|Redmi 4A|Redmi 4X|Redmi 5|Redmi 5 Plus|Redmi 5A|Redmi 6|Redmi 6 Pro|Redmi 6A|Redmi 7|Redmi 7 Pro|Redmi 7A|Redmi 8|Redmi 8A|Redmi 8A Pro|Redmi 9|Redmi 9 Power|Redmi 9 Prime|Redmi 9A|Redmi 9AT|Redmi 9C|Redmi 9C NFC|Redmi 9i|Redmi 9T|Redmi A1|Redmi A1+|Redmi A2|Redmi A2 Plus|Redmi A2+|Redmi Go|Redmi K20|Redmi K20 Pro|Redmi K20 Pro Premium Edition|Redmi K30|Redmi K30 (5G)|Redmi K30 (5G) Speed Edition|Redmi K30 Pro|Redmi K30 Pro Zoom|Redmi K30 Pro Zoom Edition|Redmi K30 Ultra|Redmi K30 Ultra (5G)|Redmi K30i (5G)|Redmi K30S|Redmi K30S Ultra|Redmi K40|Redmi K40 (5G)|Redmi K40 Gaming|Redmi K40 Pro|Redmi K40 Pro (5G)|Redmi K40S (5G)|Redmi K50|Redmi K50 Gaming (5G)|Redmi K50 Pro|Redmi K50 Ultra|Redmi K50i|Redmi K60|Redmi K60 Pro|Redmi K60 Ultra|Redmi K60E|Redmi K70|Redmi K70 Pro|Redmi Note|Redmi Note (5G)|Redmi Note 1|Redmi Note 10|Redmi Note 10 (5G)|Redmi Note 10 Lite|Redmi Note 10 Pro|Redmi Note 10 Pro (5G)|Redmi Note 10 Pro Max|Redmi Note 10S|Redmi Note 10T|Redmi Note 10T (5G)|Redmi Note 11|Redmi Note 11 Pro|Redmi Note 11 Pro (5G)|Redmi Note 11 Pro+|Redmi Note 11 Pro+ (5G)|Redmi Note 11 SE|Redmi Note 11E|Redmi Note 11E Pro|Redmi Note 11R|Redmi Note 11S|Redmi Note 11S (5G)|Redmi Note 11T (5G)|Redmi Note 11T Pro (5G)|Redmi Note 12|Redmi Note 12 (5G)|Redmi Note 12 Discovery|Redmi Note 12 Pro|Redmi Note 12 Pro (5G)|Redmi Note 12 Pro Speed|Redmi Note 12 Pro+|Redmi Note 12 Pro+ (5G)|Redmi Note 12R|Redmi Note 12S|Redmi Note 12T|Redmi Note 12T Pro|Redmi Note 13|Redmi Note 13 Pro|Redmi Note 13 Pro+|Redmi Note 2|Redmi Note 3|Redmi Note 3 Pro|Redmi Note 4|Redmi Note 4X|Redmi Note 5|Redmi Note 5 Pro|Redmi Note 5A|Redmi Note 5A Lite|Redmi No""te 5A Prime|Redmi Note 6 Pro|Redmi Note 7|Redmi Note 7 Pro|Redmi Note 7S|Redmi Note 8|Redmi Note 8 Pro|Redmi Note 8T|Redmi Note 9|Redmi Note 9 (5G)|Redmi Note 9 Pro|Redmi Note 9 Pro (5G)|Redmi Note 9 Pro Max|Redmi Note 9S|Redmi Note 9T|Redmi Note 9T (5G)|Redmi Pad|Redmi Pad SE|Redmi Pro|Redmi Red Rice|Redmi S2";
static const char __pyx_k_https_whatmyuseragent_com_brand[] = "https://whatmyuseragent.com/brand/";
static const char __pyx_k_sedang_mengambil_data_useragent[] = "] sedang mengambil data useragent...";
static const char __pyx_k_wv_AppleWebKit_537_36_KHTML_lik[] = "; wv) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/";
static const char __pyx_k_68747470733A2F2F6368726F6D652E75[] = "68747470733A2F2F6368726F6D652E7570746F646F776E2E636F6D2F616E64726F69642F617070732F31383437302F76657273696F6E732F30";
static const char __pyx_k_68747470733A2F2F706173746562696E[] = "68747470733A2F2F706173746562696E2E636F6D2F7261772F537158624B595467";
static const char __pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s[] = "Dalvik/2.1.0 (Linux; U; Android %s; %s %s) [FBAN/TalkForAndroidNative;FBAV/%s;FBPN/com.facebook.talk;FBLC/%s;FBBV/%s;FBCR/%s;FBMF/%s;FBBD/%s;FBDV/%s;FBSV/%s;FBCA/%s:null;FBDM/{density=2.0,width=720,height=1569};FB_FW/1;]";
static const char __pyx_k_Dalvik_2_1_0_iPhone_CPU_iPhone_O[] = "Dalvik/2.1.0 (iPhone; CPU iPhone OS {} like Mac OS X) [FBAN/FBIOS;FBDV/iPhone{},{};FBMD/iPhone;FBSN/iOS;FBSV/{};FBSS/{};FBID/phone;FBLC/{};FBOP/{}]";
static const char __pyx_k_Mozilla_5_0_Linux_Android_10_K_A[] = "Mozilla/5.0 (Linux; Android 10; K) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/";
static const char __pyx_k_Mozilla_5_0_Windows_NT_10_0_Win6[] = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/";
static const char __pyx_k_Mozilla_5_0_X11_Linux_x86_64_App[] = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/";
static const char __pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s_2[] = "Dalvik/2.1.0 (Linux; U; Android %s; %s %s) [FBAN/MessengerLite;FBAV/%s;FBPN/com.facebook.mlite;FBLC/%s;FBBV/%s;FBCR/%s;FBMF/%s;FBBD/%s;FBDV/%s;FBSV/%s;FBCA/%s:null;FBDM/{density=2.0,width=720,height=1569};]";
static const char __pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s_3[] = "Dalvik/2.1.0 (Linux; U; Android %s; %s %s) [FBAN/FB4A;FBAV/%s;FBPN/com.facebook.katana;FBLC/%s;FBBV/%s;FBCR/%s;FBMF/%s;FBBD/%s;FBDV/%s;FBSV/%s;FBCA/%s:null;FBDM/{density=2.0,width=720,height=1448};FB_FW/1;FBRV/0;] FBBK/1";
static const char __pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s_4[] = "Dalvik/2.1.0 (Linux; U; Android %s; %s %s) [FBAN/Orca-Android;FBAV/%s;FBPN/com.facebook.orca;FBLC/%s;FBBV/%s;FBCR/%s;FBMF/%s;FBBD/%s;FBDV/%s;FBSV/%s;FBCA/%s:null;FBDM/{density=%s.0,width=1080,height=2148};FB_FW/1;] FBBK/1";
static const char __pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s_5[] = "Dalvik/2.1.0 (Linux; U; Android %s; %s %s) [FBAN/EMA;FBBV/%s;FBAV/%s;FBDV/%s;FBLC/%s;FBNG/%s;FBMNT/METERED;FBDM/{density=3.0}]";
static const char __pyx_k_Dalvik_2_1_0_iPhone_CPU_iPhone_O_2[] = "Dalvik/2.1.0 (iPhone; CPU iPhone OS {} like Mac OS X) [FBAN/FBIOS;FBAV/{};FBBV/{};FBDV/iPhone{},{};FBMD/iPhone;FBSN/iOS;FBSV/{};FBSS/{};FBID/phone;FBLC/{};FBOP/{};FBRV/{}]";
static const char __pyx_k_Dalvik_2_1_0_iPhone_CPU_iPhone_O_3[] = "Dalvik/2.1.0 (iPhone; CPU iPhone OS {} like Mac OS X) [FBAN/MessengerForiOS;FBAV/{};FBBV/{};FBDV/iPhone{},{};FBMD/iPhone;FBSN/iOS;FBSV/{};FBSS/{};FBCR/{};FBID/phone;FBLC/{};FBOP/{};FBRV/{}]";
static const char __pyx_k_Dalvik_2_1_0_iPhone_CPU_iPhone_O_4[] = "Dalvik/2.1.0 (iPhone; CPU iPhone OS {} like Mac OS X) [FBAN/MessengerLiteForiOS;FBAV/{};FBBV/{};FBDV/iPhone{},{};FBMD/iPhone;FBSN/iOS;FBSV/{};FBSS/{};FBCR/;FBID/phone;FBLC/id;FBOP/{}]";
static const char __pyx_k_Mozilla_5_0_Linux_Android_10_K_A_2[] = "Mozilla/5.0 (Linux; Android 10; K) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Mobile Safari/537.36";
static PyObject *__pyx_kp_s_01_Oktober_2021;
static PyObject *__pyx_kp_s_0_0;
static PyObject *__pyx_kp_s_122_0_0_0;
static PyObject *__pyx_kp_s_1234567890;
static PyObject *__pyx_kp_s_1_91m;
static PyObject *__pyx_kp_s_1_92m;
static PyObject *__pyx_kp_s_1_93m;
static PyObject *__pyx_kp_s_1_97m;
static PyObject *__pyx_kp_s_3G;
static PyObject *__pyx_kp_s_3SinyalKuatHemat;
static PyObject *__pyx_kp_s_4G;
static PyObject *__pyx_kp_s_5G;
static PyObject *__pyx_kp_s_68747470733A2F2F6368726F6D652E75;
static PyObject *__pyx_kp_s_68747470733A2F2F706173746562696E;
static PyObject *__pyx_n_s_AXIS;
static PyObject *__pyx_kp_s_Android_Build;
static PyObject *__pyx_kp_u_AppleWebKit_540_77_KHTML_like_G;
static PyObject *__pyx_n_s_Author;
static PyObject *__pyx_kp_s_Babas_XD;
static PyObject *__pyx_n_s_BeautifulSoup;
static PyObject *__pyx_kp_s_Blade_Premium_Facebook_Crack;
static PyObject *__pyx_n_s_Build;
static PyObject *__pyx_kp_s_Build_0;
static PyObject *__pyx_n_s_Create;
static PyObject *__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s;
static PyObject *__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s_2;
static PyObject *__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s_3;
static PyObject *__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s_4;
static PyObject *__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s_5;
static PyObject *__pyx_kp_s_Dalvik_2_1_0_iPhone_CPU_iPhone_O;
static PyObject *__pyx_kp_s_Dalvik_2_1_0_iPhone_CPU_iPhone_O_2;
static PyObject *__pyx_kp_s_Dalvik_2_1_0_iPhone_CPU_iPhone_O_3;
static PyObject *__pyx_kp_s_Dalvik_2_1_0_iPhone_CPU_iPhone_O_4;
static PyObject *__pyx_n_s_Facebook;
static PyObject *__pyx_n_s_Github;
static PyObject *__pyx_n_s_H;
static PyObject *__pyx_n_s_INDOSAT;
static PyObject *__pyx_n_s_Indosat;
static PyObject *__pyx_n_s_K;
static PyObject *__pyx_n_s_M;
static PyObject *__pyx_kp_u_Mobile_Safari_537_36;
static PyObject *__pyx_kp_u_Mozilla_5_0_Linux_Android;
static PyObject *__pyx_kp_u_Mozilla_5_0_Linux_Android_10_K_A;
static PyObject *__pyx_kp_s_Mozilla_5_0_Linux_Android_10_K_A_2;
static PyObject *__pyx_kp_u_Mozilla_5_0_Macintosh_Intel_Mac;
static PyObject *__pyx_kp_u_Mozilla_5_0_Windows_NT_10_0_Win6;
static PyObject *__pyx_kp_u_Mozilla_5_0_X11_Linux_x86_64_App;
static PyObject *__pyx_n_s_OPM1;
static PyObject *__pyx_n_s_P;
static PyObject *__pyx_n_s_PPR1;
static PyObject *__pyx_n_s_QP1A;
static PyObject *__pyx_n_s_RKQ1;
static PyObject *__pyx_n_s_RP1A;
static PyObject *__pyx_kp_s_Redmi_Go_Redmi_Note_7_Pro_Redmi;
static PyObject *__pyx_kp_s_Redmi_Note_10_Pro;
static PyObject *__pyx_n_s_SKQ1;
static PyObject *__pyx_n_s_SP1A;
static PyObject *__pyx_kp_u_Safari_232_65;
static PyObject *__pyx_kp_u_Safari_537_36;
static PyObject *__pyx_n_s_Script;
static PyObject *__pyx_n_s_Session;
static PyObject *__pyx_n_s_TP1A;
static PyObject *__pyx_n_s_Telkomsel;
static PyObject *__pyx_kp_s_Tsel_PakaiMasker;
static PyObject *__pyx_kp_s_Tsel_PemiluDamai;
static PyObject *__pyx_n_s_WIFI;
static PyObject *__pyx_n_s_XL;
static PyObject *__pyx_kp_s_XL_Axiata;
static PyObject *__pyx_n_s_Xiaomi;
static PyObject *__pyx_kp_s__11;
static PyObject *__pyx_kp_s__12;
static PyObject *__pyx_kp_s__14;
static PyObject *__pyx_n_s__21;
static PyObject *__pyx_n_u__21;
static PyObject *__pyx_kp_s__23;
static PyObject *__pyx_kp_u__30;
static PyObject *__pyx_kp_u__31;
static PyObject *__pyx_kp_u__4;
static PyObject *__pyx_kp_u__5;
static PyObject *__pyx_kp_s__8;
static PyObject *__pyx_kp_s__9;
static PyObject *__pyx_n_s_andro;
static PyObject *__pyx_n_s_api_ios;
static PyObject *__pyx_n_s_api_ios_locals_genexpr;
static PyObject *__pyx_n_s_append;
static PyObject *__pyx_n_s_ar_AE;
static PyObject *__pyx_n_s_ar_AR;
static PyObject *__pyx_n_s_ar_JO;
static PyObject *__pyx_n_s_ar_SA;
static PyObject *__pyx_n_s_args;
static PyObject *__pyx_kp_s_au_asus;
static PyObject *__pyx_n_s_az_AZ;
static PyObject *__pyx_n_s_b16decode;
static PyObject *__pyx_n_s_b16encode;
static PyObject *__pyx_n_s_bas;
static PyObject *__pyx_n_s_base64;
static PyObject *__pyx_n_s_bg_BG;
static PyObject *__pyx_n_s_blade_team;
static PyObject *__pyx_n_s_bs4;
static PyObject *__pyx_n_s_bs_BA;
static PyObject *__pyx_n_s_build;
static PyObject *__pyx_kp_s_by_U_PemiluDamai;
static PyObject *__pyx_n_s_check_output;
static PyObject *__pyx_n_s_choice;
static PyObject *__pyx_n_s_class;
static PyObject *__pyx_n_s_cline_in_traceback;
static PyObject *__pyx_n_s_close;
static PyObject *__pyx_n_s_cs_CZ;
static PyObject *__pyx_n_s_data;
static PyObject *__pyx_n_s_data_ua;
static PyObject *__pyx_n_s_de_AT;
static PyObject *__pyx_n_s_de_CH;
static PyObject *__pyx_n_s_de_DE;
static PyObject *__pyx_n_s_decode;
static PyObject *__pyx_n_s_e;
static PyObject *__pyx_n_s_el_GR;
static PyObject *__pyx_n_s_en_AU;
static PyObject *__pyx_n_s_en_CA;
static PyObject *__pyx_n_s_en_GB;
static PyObject *__pyx_n_s_en_IE;
static PyObject *__pyx_n_s_en_IN;
static PyObject *__pyx_n_s_en_NZ;
static PyObject *__pyx_n_s_en_PH;
static PyObject *__pyx_n_s_en_SE;
static PyObject *__pyx_n_s_en_US;
static PyObject *__pyx_n_s_en_ZA;
static PyObject *__pyx_n_s_encode;
static PyObject *__pyx_n_s_es_CL;
static PyObject *__pyx_n_s_es_CO;
static PyObject *__pyx_n_s_es_ES;
static PyObject *__pyx_n_s_es_LA;
static PyObject *__pyx_n_s_es_MX;
static PyObject *__pyx_n_s_es_PE;
static PyObject *__pyx_n_s_es_SV;
static PyObject *__pyx_n_s_es_US;
static PyObject *__pyx_n_s_extend;
static PyObject *__pyx_n_s_fa_IR;
static PyObject *__pyx_kp_s_facebook_com_ROZHBASXY;
static PyObject *__pyx_n_s_fb_lite;
static PyObject *__pyx_n_s_fb_ori;
static PyObject *__pyx_n_s_fbcr;
static PyObject *__pyx_n_s_files;
static PyObject *__pyx_n_s_find_all;
static PyObject *__pyx_n_s_findall;
static PyObject *__pyx_n_s_for_ios;
static PyObject *__pyx_n_s_format;
static PyObject *__pyx_n_s_fr_BE;
static PyObject *__pyx_n_s_fr_CA;
static PyObject *__pyx_n_s_fr_CH;
static PyObject *__pyx_n_s_fr_FR;
static PyObject *__pyx_n_s_ga_IE;
static PyObject *__pyx_n_s_genexpr;
static PyObject *__pyx_n_s_get;
static PyObject *__pyx_kp_s_getprop_ro_product_cpu_abilist;
static PyObject *__pyx_kp_s_github_com_RozhBasXYZ;
static PyObject *__pyx_n_s_headers;
static PyObject *__pyx_n_s_heker_asu;
static PyObject *__pyx_n_s_heker_baik;
static PyObject *__pyx_n_s_hr_HR;
static PyObject *__pyx_kp_s_html_parser;
static PyObject *__pyx_kp_s_https_whatmyuseragent_com_brand;
static PyObject *__pyx_n_s_hu_HU;
static PyObject *__pyx_n_s_hy_AM;
static PyObject *__pyx_kp_s_if_infinix;
static PyObject *__pyx_n_s_import;
static PyObject *__pyx_n_s_in_ID;
static PyObject *__pyx_n_s_ios;
static PyObject *__pyx_n_s_iphone;
static PyObject *__pyx_n_s_it_IT;
static PyObject *__pyx_n_s_it_SM;
static PyObject *__pyx_n_s_iw_IL;
static PyObject *__pyx_kp_s_iz_itel;
static PyObject *__pyx_n_s_join;
static PyObject *__pyx_n_s_json;
static PyObject *__pyx_n_s_ka_GE;
static PyObject *__pyx_n_s_kode;
static PyObject *__pyx_n_s_link;
static PyObject *__pyx_n_s_list_ua;
static PyObject *__pyx_n_s_locale;
static PyObject *__pyx_n_s_lv_LV;
static PyObject *__pyx_n_s_main;
static PyObject *__pyx_n_s_menu;
static PyObject *__pyx_kp_s_menu_py;
static PyObject *__pyx_n_s_merk;
static PyObject *__pyx_n_s_mes_ios;
static PyObject *__pyx_n_s_mes_kids;
static PyObject *__pyx_n_s_mes_lite;
static PyObject *__pyx_n_s_mes_lite_ios;
static PyObject *__pyx_n_s_mes_ori;
static PyObject *__pyx_n_s_name;
static PyObject *__pyx_n_s_nb_NO;
static PyObject *__pyx_n_s_nl_BE;
static PyObject *__pyx_n_s_nl_NL;
static PyObject *__pyx_kp_s_op_oppo;
static PyObject *__pyx_n_s_os;
static PyObject *__pyx_n_s_parser;
static PyObject *__pyx_n_s_pl_PL;
static PyObject *__pyx_n_s_print;
static PyObject *__pyx_n_s_pt_BR;
static PyObject *__pyx_n_s_pt_PT;
static PyObject *__pyx_n_s_randint;
static PyObject *__pyx_n_s_random;
static PyObject *__pyx_n_s_range;
static PyObject *__pyx_n_s_rc;
static PyObject *__pyx_n_s_re;
static PyObject *__pyx_kp_s_re_realme;
static PyObject *__pyx_n_s_replace;
static PyObject *__pyx_n_s_requests;
static PyObject *__pyx_n_s_ro_RO;
static PyObject *__pyx_n_s_rozh;
static PyObject *__pyx_n_s_rr;
static PyObject *__pyx_n_s_ru_BY;
static PyObject *__pyx_n_s_ru_KG;
static PyObject *__pyx_n_s_ru_KZ;
static PyObject *__pyx_n_s_ru_RU;
static PyObject *__pyx_n_s_ru_UA;
static PyObject *__pyx_kp_s_sa_samsung;
static PyObject *__pyx_kp_u_sedang_mengambil_data_useragent;
static PyObject *__pyx_n_s_send;
static PyObject *__pyx_n_s_ses;
static PyObject *__pyx_n_s_shell;
static PyObject *__pyx_n_s_sk_SK;
static PyObject *__pyx_n_s_sl_SI;
static PyObject *__pyx_n_s_split;
static PyObject *__pyx_n_s_sr_RS;
static PyObject *__pyx_n_s_string;
static PyObject *__pyx_n_s_subprocess;
static PyObject *__pyx_kp_s_tb_tecno_mobile;
static PyObject *__pyx_n_s_td;
static PyObject *__pyx_n_s_test;
static PyObject *__pyx_n_s_text;
static PyObject *__pyx_n_s_th_TH;
static PyObject *__pyx_n_s_throw;
static PyObject *__pyx_n_s_tipe_dev;
static PyObject *__pyx_n_s_tr_TR;
static PyObject *__pyx_n_s_ua_api;
static PyObject *__pyx_n_s_ua_api_locals_genexpr;
static PyObject *__pyx_n_s_ua_biasa;
static PyObject *__pyx_n_s_ua_mes;
static PyObject *__pyx_n_s_ua_ori;
static PyObject *__pyx_n_s_ua_web;
static PyObject *__pyx_n_s_uk_UA;
static PyObject *__pyx_kp_s_user_agent;
static PyObject *__pyx_n_s_useragent;
static PyObject *__pyx_kp_s_utf_8;
static PyObject *__pyx_n_s_uz_UZ;
static PyObject *__pyx_n_s_value;
static PyObject *__pyx_n_s_versi;
static PyObject *__pyx_n_s_versi_chrome;
static PyObject *__pyx_n_s_version;
static PyObject *__pyx_kp_s_vv_vivo;
static PyObject *__pyx_kp_u_wv_AppleWebKit_537_36_KHTML_lik;
static PyObject *__pyx_kp_s_xi_xiaomi;
static PyObject *__pyx_n_s_xiaomi;
static PyObject *__pyx_n_s_xyz;
static PyObject *__pyx_pf_4menu_heker_asu(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_files); 
static PyObject *__pyx_pf_4menu_2heker_baik(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_files); 
static PyObject *__pyx_pf_4menu_4ua_biasa(CYTHON_UNUSED PyObject *__pyx_self); 
static PyObject *__pyx_pf_4menu_6ua_api_genexpr(PyObject *__pyx_self); 
static PyObject *__pyx_pf_4menu_6ua_api(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_value); 
static PyObject *__pyx_pf_4menu_7api_ios_genexpr(PyObject *__pyx_self); 
static PyObject *__pyx_pf_4menu_7api_ios_3genexpr(PyObject *__pyx_self); 
static PyObject *__pyx_pf_4menu_7api_ios_6genexpr(PyObject *__pyx_self); 
static PyObject *__pyx_pf_4menu_7api_ios_9genexpr(PyObject *__pyx_self); 
static PyObject *__pyx_pf_4menu_7api_ios_12genexpr(PyObject *__pyx_self); 
static PyObject *__pyx_pf_4menu_7api_ios_15genexpr(PyObject *__pyx_self); 
static PyObject *__pyx_pf_4menu_7api_ios_18genexpr(PyObject *__pyx_self); 
static PyObject *__pyx_pf_4menu_7api_ios_21genexpr(PyObject *__pyx_self); 
static PyObject *__pyx_pf_4menu_7api_ios_24genexpr(PyObject *__pyx_self); 
static PyObject *__pyx_pf_4menu_8api_ios(CYTHON_UNUSED PyObject *__pyx_self); 
static PyObject *__pyx_pf_4menu_10ua_web(CYTHON_UNUSED PyObject *__pyx_self); 
static PyObject *__pyx_tp_new_4menu___pyx_scope_struct__ua_api(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_1_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_2_api_ios(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_3_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_4_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_5_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_6_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_7_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_8_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_9_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_10_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_11_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_int_0;
static PyObject *__pyx_int_1;
static PyObject *__pyx_int_3;
static PyObject *__pyx_int_5;
static PyObject *__pyx_int_8;
static PyObject *__pyx_int_9;
static PyObject *__pyx_int_10;
static PyObject *__pyx_int_14;
static PyObject *__pyx_int_15;
static PyObject *__pyx_int_17;
static PyObject *__pyx_int_20;
static PyObject *__pyx_int_99;
static PyObject *__pyx_int_100;
static PyObject *__pyx_int_444;
static PyObject *__pyx_int_445;
static PyObject *__pyx_int_111111;
static PyObject *__pyx_int_333333;
static PyObject *__pyx_tuple_;
static PyObject *__pyx_tuple__2;
static PyObject *__pyx_tuple__3;
static PyObject *__pyx_tuple__6;
static PyObject *__pyx_tuple__7;
static PyObject *__pyx_tuple__10;
static PyObject *__pyx_tuple__13;
static PyObject *__pyx_tuple__15;
static PyObject *__pyx_tuple__16;
static PyObject *__pyx_tuple__17;
static PyObject *__pyx_tuple__18;
static PyObject *__pyx_tuple__19;
static PyObject *__pyx_tuple__20;
static PyObject *__pyx_tuple__22;
static PyObject *__pyx_tuple__24;
static PyObject *__pyx_tuple__25;
static PyObject *__pyx_tuple__26;
static PyObject *__pyx_tuple__28;
static PyObject *__pyx_tuple__32;
static PyObject *__pyx_tuple__33;
static PyObject *__pyx_tuple__34;
static PyObject *__pyx_tuple__35;
static PyObject *__pyx_tuple__37;
static PyObject *__pyx_tuple__39;
static PyObject *__pyx_codeobj__27;
static PyObject *__pyx_codeobj__29;
static PyObject *__pyx_codeobj__36;
static PyObject *__pyx_codeobj__38;
static PyObject *__pyx_codeobj__40;
static PyObject *__pyx_codeobj__41;





static PyObject *__pyx_pw_4menu_1heker_asu(PyObject *__pyx_self, PyObject *__pyx_v_files); 
static PyMethodDef __pyx_mdef_4menu_1heker_asu = {"heker_asu", (PyCFunction)__pyx_pw_4menu_1heker_asu, METH_O, 0};
static PyObject *__pyx_pw_4menu_1heker_asu(PyObject *__pyx_self, PyObject *__pyx_v_files) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("heker_asu (wrapper)", 0);
  __pyx_r = __pyx_pf_4menu_heker_asu(__pyx_self, ((PyObject *)__pyx_v_files));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4menu_heker_asu(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_files) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("heker_asu", 0);

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_base64); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_b16decode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_3, __pyx_v_files) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_v_files);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_decode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_2, __pyx_kp_s_utf_8) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_kp_s_utf_8);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("menu.heker_asu", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4menu_3heker_baik(PyObject *__pyx_self, PyObject *__pyx_v_files); 
static PyMethodDef __pyx_mdef_4menu_3heker_baik = {"heker_baik", (PyCFunction)__pyx_pw_4menu_3heker_baik, METH_O, 0};
static PyObject *__pyx_pw_4menu_3heker_baik(PyObject *__pyx_self, PyObject *__pyx_v_files) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("heker_baik (wrapper)", 0);
  __pyx_r = __pyx_pf_4menu_2heker_baik(__pyx_self, ((PyObject *)__pyx_v_files));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4menu_2heker_baik(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_files) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("heker_baik", 0);

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_base64); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_b16encode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_files, __pyx_n_s_encode); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
    }
  }
  __pyx_t_3 = (__pyx_t_6) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_6) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_5, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_decode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_2, __pyx_kp_s_utf_8) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_kp_s_utf_8);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("menu.heker_baik", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4menu_5ua_biasa(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); 
static PyMethodDef __pyx_mdef_4menu_5ua_biasa = {"ua_biasa", (PyCFunction)__pyx_pw_4menu_5ua_biasa, METH_NOARGS, 0};
static PyObject *__pyx_pw_4menu_5ua_biasa(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("ua_biasa (wrapper)", 0);
  __pyx_r = __pyx_pf_4menu_4ua_biasa(__pyx_self);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4menu_4ua_biasa(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_v_rr = NULL;
  PyObject *__pyx_v_rc = NULL;
  PyObject *__pyx_v_andro = NULL;
  PyObject *__pyx_v_build = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  Py_ssize_t __pyx_t_9;
  Py_UCS4 __pyx_t_10;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("ua_biasa", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_random); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_randint); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_rr = __pyx_t_2;
  __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_random); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_choice); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_rc = __pyx_t_1;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple_, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_andro = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_kp_s_Build_0, __pyx_n_s_format); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 49, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = PyList_New(6); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 49, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_n_s_QP1A);
  __Pyx_GIVEREF(__pyx_n_s_QP1A);
  PyList_SET_ITEM(__pyx_t_4, 0, __pyx_n_s_QP1A);
  __Pyx_INCREF(__pyx_n_s_SP1A);
  __Pyx_GIVEREF(__pyx_n_s_SP1A);
  PyList_SET_ITEM(__pyx_t_4, 1, __pyx_n_s_SP1A);
  __Pyx_INCREF(__pyx_n_s_PPR1);
  __Pyx_GIVEREF(__pyx_n_s_PPR1);
  PyList_SET_ITEM(__pyx_t_4, 2, __pyx_n_s_PPR1);
  __Pyx_INCREF(__pyx_n_s_RP1A);
  __Pyx_GIVEREF(__pyx_n_s_RP1A);
  PyList_SET_ITEM(__pyx_t_4, 3, __pyx_n_s_RP1A);
  __Pyx_INCREF(__pyx_n_s_OPM1);
  __Pyx_GIVEREF(__pyx_n_s_OPM1);
  PyList_SET_ITEM(__pyx_t_4, 4, __pyx_n_s_OPM1);
  __Pyx_INCREF(__pyx_n_s_TP1A);
  __Pyx_GIVEREF(__pyx_n_s_TP1A);
  PyList_SET_ITEM(__pyx_t_4, 5, __pyx_n_s_TP1A);
  __Pyx_INCREF(__pyx_v_rc);
  __pyx_t_5 = __pyx_v_rc; __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
    }
  }
  __pyx_t_3 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_6, __pyx_t_4) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 49, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__2, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 49, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__3, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 49, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_6 = NULL;
  __pyx_t_7 = 0;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_7 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[4] = {__pyx_t_6, __pyx_t_3, __pyx_t_5, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_7, 3+__pyx_t_7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 49, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[4] = {__pyx_t_6, __pyx_t_3, __pyx_t_5, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_7, 3+__pyx_t_7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 49, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  {
    __pyx_t_8 = PyTuple_New(3+__pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 49, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    if (__pyx_t_6) {
      __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_6); __pyx_t_6 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_8, 0+__pyx_t_7, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_8, 1+__pyx_t_7, __pyx_t_5);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_8, 2+__pyx_t_7, __pyx_t_4);
    __pyx_t_3 = 0;
    __pyx_t_5 = 0;
    __pyx_t_4 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_8, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 49, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_build = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyTuple_New(9); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 50, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_9 = 0;
  __pyx_t_10 = 127;
  __Pyx_INCREF(__pyx_kp_u_Mozilla_5_0_Linux_Android);
  __pyx_t_9 += 28;
  __Pyx_GIVEREF(__pyx_kp_u_Mozilla_5_0_Linux_Android);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u_Mozilla_5_0_Linux_Android);
  __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_v_andro, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 50, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_10 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_10) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_10;
  __pyx_t_9 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_2);
  __pyx_t_2 = 0;
  __Pyx_INCREF(__pyx_kp_u__4);
  __pyx_t_9 += 2;
  __Pyx_GIVEREF(__pyx_kp_u__4);
  PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_kp_u__4);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_list_ua); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 50, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_INCREF(__pyx_v_rc);
  __pyx_t_4 = __pyx_v_rc; __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_5, __pyx_t_8) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_8);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 50, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 50, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_10 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_10) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_10;
  __pyx_t_9 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_1, 3, __pyx_t_4);
  __pyx_t_4 = 0;
  __Pyx_INCREF(__pyx_kp_u__5);
  __pyx_t_9 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__5);
  PyTuple_SET_ITEM(__pyx_t_1, 4, __pyx_kp_u__5);
  __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_v_build, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 50, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_10 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_10) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_10;
  __pyx_t_9 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_1, 5, __pyx_t_4);
  __pyx_t_4 = 0;
  __Pyx_INCREF(__pyx_kp_u_wv_AppleWebKit_537_36_KHTML_lik);
  __pyx_t_9 += 64;
  __Pyx_GIVEREF(__pyx_kp_u_wv_AppleWebKit_537_36_KHTML_lik);
  PyTuple_SET_ITEM(__pyx_t_1, 6, __pyx_kp_u_wv_AppleWebKit_537_36_KHTML_lik);
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_versi_chrome); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 50, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_t_4, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 50, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_10 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_10) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_10;
  __pyx_t_9 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_1, 7, __pyx_t_2);
  __pyx_t_2 = 0;
  __Pyx_INCREF(__pyx_kp_u_Mobile_Safari_537_36);
  __pyx_t_9 += 21;
  __Pyx_GIVEREF(__pyx_kp_u_Mobile_Safari_537_36);
  PyTuple_SET_ITEM(__pyx_t_1, 8, __pyx_kp_u_Mobile_Safari_537_36);
  __pyx_t_2 = __Pyx_PyUnicode_Join(__pyx_t_1, 9, __pyx_t_9, __pyx_t_10); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 50, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("menu.ua_biasa", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_rr);
  __Pyx_XDECREF(__pyx_v_rc);
  __Pyx_XDECREF(__pyx_v_andro);
  __Pyx_XDECREF(__pyx_v_build);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4menu_7ua_api(PyObject *__pyx_self, PyObject *__pyx_v_value); 
static PyMethodDef __pyx_mdef_4menu_7ua_api = {"ua_api", (PyCFunction)__pyx_pw_4menu_7ua_api, METH_O, 0};
static PyObject *__pyx_pw_4menu_7ua_api(PyObject *__pyx_self, PyObject *__pyx_v_value) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("ua_api (wrapper)", 0);
  __pyx_r = __pyx_pf_4menu_6ua_api(__pyx_self, ((PyObject *)__pyx_v_value));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4menu_6ua_api_2generator(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 



static PyObject *__pyx_pf_4menu_6ua_api_genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr *)__pyx_tp_new_4menu___pyx_scope_struct_1_genexpr(__pyx_ptype_4menu___pyx_scope_struct_1_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 58, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4menu___pyx_scope_struct__ua_api *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4menu_6ua_api_2generator, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_ua_api_locals_genexpr, __pyx_n_s_menu); if (unlikely(!gen)) __PYX_ERR(0, 58, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("menu.ua_api.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4menu_6ua_api_2generator(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  long __pyx_t_1;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L6_resume_from_yield;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 58, __pyx_L1_error)
  for (__pyx_t_1 = 0; __pyx_t_1 < 9; __pyx_t_1+=1) {
    __pyx_cur_scope->__pyx_v_z = __pyx_t_1;
    if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_rc)) { __Pyx_RaiseClosureNameError("rc"); __PYX_ERR(0, 58, __pyx_L1_error) }
    __Pyx_INCREF(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_rc);
    __pyx_t_3 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_rc; __pyx_t_4 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_4)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_4);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_2 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_4, __pyx_kp_s_1234567890) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_kp_s_1234567890);
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 58, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_r = __pyx_t_2;
    __pyx_t_2 = 0;
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_1;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L6_resume_from_yield:;
    __pyx_t_1 = __pyx_cur_scope->__pyx_t_0;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 58, __pyx_L1_error)
  }
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_4menu_6ua_api(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_value) {
  struct __pyx_obj_4menu___pyx_scope_struct__ua_api *__pyx_cur_scope;
  PyObject *__pyx_v_rr = NULL;
  PyObject *__pyx_v_andro = NULL;
  PyObject *__pyx_v_build = NULL;
  PyObject *__pyx_v_tipe_dev = NULL;
  PyObject *__pyx_v_fbcr = NULL;
  PyObject *__pyx_v_kode = NULL;
  PyObject *__pyx_v_locale = NULL;
  PyObject *__pyx_v_merk = NULL;
  PyObject *__pyx_v_versi = NULL;
  PyObject *__pyx_v_mes_kids = NULL;
  PyObject *__pyx_v_mes_lite = NULL;
  PyObject *__pyx_v_fb_ori = NULL;
  PyObject *__pyx_v_mes_ori = NULL;
  PyObject *__pyx_v_fb_lite = NULL;
  PyObject *__pyx_gb_4menu_6ua_api_2generator = 0;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_t_9;
  int __pyx_t_10;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("ua_api", 0);
  __pyx_cur_scope = (struct __pyx_obj_4menu___pyx_scope_struct__ua_api *)__pyx_tp_new_4menu___pyx_scope_struct__ua_api(__pyx_ptype_4menu___pyx_scope_struct__ua_api, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct__ua_api *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 53, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_random); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_randint); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_rr = __pyx_t_2;
  __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_random); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_choice); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_cur_scope->__pyx_v_rc = __pyx_t_1;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__6, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_andro = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_kp_s_Build_0, __pyx_n_s_format); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = PyList_New(8); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_n_s_QP1A);
  __Pyx_GIVEREF(__pyx_n_s_QP1A);
  PyList_SET_ITEM(__pyx_t_4, 0, __pyx_n_s_QP1A);
  __Pyx_INCREF(__pyx_n_s_SP1A);
  __Pyx_GIVEREF(__pyx_n_s_SP1A);
  PyList_SET_ITEM(__pyx_t_4, 1, __pyx_n_s_SP1A);
  __Pyx_INCREF(__pyx_n_s_PPR1);
  __Pyx_GIVEREF(__pyx_n_s_PPR1);
  PyList_SET_ITEM(__pyx_t_4, 2, __pyx_n_s_PPR1);
  __Pyx_INCREF(__pyx_n_s_RP1A);
  __Pyx_GIVEREF(__pyx_n_s_RP1A);
  PyList_SET_ITEM(__pyx_t_4, 3, __pyx_n_s_RP1A);
  __Pyx_INCREF(__pyx_n_s_OPM1);
  __Pyx_GIVEREF(__pyx_n_s_OPM1);
  PyList_SET_ITEM(__pyx_t_4, 4, __pyx_n_s_OPM1);
  __Pyx_INCREF(__pyx_n_s_TP1A);
  __Pyx_GIVEREF(__pyx_n_s_TP1A);
  PyList_SET_ITEM(__pyx_t_4, 5, __pyx_n_s_TP1A);
  __Pyx_INCREF(__pyx_n_s_RKQ1);
  __Pyx_GIVEREF(__pyx_n_s_RKQ1);
  PyList_SET_ITEM(__pyx_t_4, 6, __pyx_n_s_RKQ1);
  __Pyx_INCREF(__pyx_n_s_SKQ1);
  __Pyx_GIVEREF(__pyx_n_s_SKQ1);
  PyList_SET_ITEM(__pyx_t_4, 7, __pyx_n_s_SKQ1);
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_rc);
  __pyx_t_5 = __pyx_cur_scope->__pyx_v_rc; __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
    }
  }
  __pyx_t_3 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_6, __pyx_t_4) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__2, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__3, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_6 = NULL;
  __pyx_t_7 = 0;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_7 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[4] = {__pyx_t_6, __pyx_t_3, __pyx_t_5, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_7, 3+__pyx_t_7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 55, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[4] = {__pyx_t_6, __pyx_t_3, __pyx_t_5, __pyx_t_4};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_7, 3+__pyx_t_7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 55, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  {
    __pyx_t_8 = PyTuple_New(3+__pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 55, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    if (__pyx_t_6) {
      __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_6); __pyx_t_6 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_8, 0+__pyx_t_7, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_8, 1+__pyx_t_7, __pyx_t_5);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_8, 2+__pyx_t_7, __pyx_t_4);
    __pyx_t_3 = 0;
    __pyx_t_5 = 0;
    __pyx_t_4 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_8, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 55, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_build = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_subprocess); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_check_output); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_shell, Py_True) < 0) __PYX_ERR(0, 56, __pyx_L1_error)
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_tuple__7, __pyx_t_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_decode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_kp_s_utf_8) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_kp_s_utf_8);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_replace); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__10, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_replace); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__13, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_tipe_dev = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_2 = PyList_New(10); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_Telkomsel);
  __Pyx_GIVEREF(__pyx_n_s_Telkomsel);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_Telkomsel);
  __Pyx_INCREF(__pyx_n_s_AXIS);
  __Pyx_GIVEREF(__pyx_n_s_AXIS);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_n_s_AXIS);
  __Pyx_INCREF(__pyx_n_s_Indosat);
  __Pyx_GIVEREF(__pyx_n_s_Indosat);
  PyList_SET_ITEM(__pyx_t_2, 2, __pyx_n_s_Indosat);
  __Pyx_INCREF(__pyx_n_s_XL);
  __Pyx_GIVEREF(__pyx_n_s_XL);
  PyList_SET_ITEM(__pyx_t_2, 3, __pyx_n_s_XL);
  __Pyx_INCREF(__pyx_kp_s_3SinyalKuatHemat);
  __Pyx_GIVEREF(__pyx_kp_s_3SinyalKuatHemat);
  PyList_SET_ITEM(__pyx_t_2, 4, __pyx_kp_s_3SinyalKuatHemat);
  __Pyx_INCREF(__pyx_kp_s_Tsel_PakaiMasker);
  __Pyx_GIVEREF(__pyx_kp_s_Tsel_PakaiMasker);
  PyList_SET_ITEM(__pyx_t_2, 5, __pyx_kp_s_Tsel_PakaiMasker);
  __Pyx_INCREF(__pyx_kp_s_XL_Axiata);
  __Pyx_GIVEREF(__pyx_kp_s_XL_Axiata);
  PyList_SET_ITEM(__pyx_t_2, 6, __pyx_kp_s_XL_Axiata);
  __Pyx_INCREF(__pyx_kp_s_by_U_PemiluDamai);
  __Pyx_GIVEREF(__pyx_kp_s_by_U_PemiluDamai);
  PyList_SET_ITEM(__pyx_t_2, 7, __pyx_kp_s_by_U_PemiluDamai);
  __Pyx_INCREF(__pyx_kp_s_Tsel_PemiluDamai);
  __Pyx_GIVEREF(__pyx_kp_s_Tsel_PemiluDamai);
  PyList_SET_ITEM(__pyx_t_2, 8, __pyx_kp_s_Tsel_PemiluDamai);
  __Pyx_INCREF(__pyx_n_s_INDOSAT);
  __Pyx_GIVEREF(__pyx_n_s_INDOSAT);
  PyList_SET_ITEM(__pyx_t_2, 9, __pyx_n_s_INDOSAT);
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_rc);
  __pyx_t_4 = __pyx_cur_scope->__pyx_v_rc; __pyx_t_8 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_8)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_8);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_8, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2);
  __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_fbcr = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __pyx_pf_4menu_6ua_api_genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = __Pyx_PyString_Join(__pyx_kp_s__12, __pyx_t_1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_kode = ((PyObject*)__pyx_t_4);
  __pyx_t_4 = 0;

  
  __pyx_t_1 = PyList_New(64); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 59, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_ru_RU);
  __Pyx_GIVEREF(__pyx_n_s_ru_RU);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_ru_RU);
  __Pyx_INCREF(__pyx_n_s_en_GB);
  __Pyx_GIVEREF(__pyx_n_s_en_GB);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_s_en_GB);
  __Pyx_INCREF(__pyx_n_s_uk_UA);
  __Pyx_GIVEREF(__pyx_n_s_uk_UA);
  PyList_SET_ITEM(__pyx_t_1, 2, __pyx_n_s_uk_UA);
  __Pyx_INCREF(__pyx_n_s_en_US);
  __Pyx_GIVEREF(__pyx_n_s_en_US);
  PyList_SET_ITEM(__pyx_t_1, 3, __pyx_n_s_en_US);
  __Pyx_INCREF(__pyx_n_s_de_DE);
  __Pyx_GIVEREF(__pyx_n_s_de_DE);
  PyList_SET_ITEM(__pyx_t_1, 4, __pyx_n_s_de_DE);
  __Pyx_INCREF(__pyx_n_s_it_IT);
  __Pyx_GIVEREF(__pyx_n_s_it_IT);
  PyList_SET_ITEM(__pyx_t_1, 5, __pyx_n_s_it_IT);
  __Pyx_INCREF(__pyx_n_s_ru_UA);
  __Pyx_GIVEREF(__pyx_n_s_ru_UA);
  PyList_SET_ITEM(__pyx_t_1, 6, __pyx_n_s_ru_UA);
  __Pyx_INCREF(__pyx_n_s_ar_AE);
  __Pyx_GIVEREF(__pyx_n_s_ar_AE);
  PyList_SET_ITEM(__pyx_t_1, 7, __pyx_n_s_ar_AE);
  __Pyx_INCREF(__pyx_n_s_tr_TR);
  __Pyx_GIVEREF(__pyx_n_s_tr_TR);
  PyList_SET_ITEM(__pyx_t_1, 8, __pyx_n_s_tr_TR);
  __Pyx_INCREF(__pyx_n_s_lv_LV);
  __Pyx_GIVEREF(__pyx_n_s_lv_LV);
  PyList_SET_ITEM(__pyx_t_1, 9, __pyx_n_s_lv_LV);
  __Pyx_INCREF(__pyx_n_s_th_TH);
  __Pyx_GIVEREF(__pyx_n_s_th_TH);
  PyList_SET_ITEM(__pyx_t_1, 10, __pyx_n_s_th_TH);
  __Pyx_INCREF(__pyx_n_s_fr_FR);
  __Pyx_GIVEREF(__pyx_n_s_fr_FR);
  PyList_SET_ITEM(__pyx_t_1, 11, __pyx_n_s_fr_FR);
  __Pyx_INCREF(__pyx_n_s_sr_RS);
  __Pyx_GIVEREF(__pyx_n_s_sr_RS);
  PyList_SET_ITEM(__pyx_t_1, 12, __pyx_n_s_sr_RS);
  __Pyx_INCREF(__pyx_n_s_hu_HU);
  __Pyx_GIVEREF(__pyx_n_s_hu_HU);
  PyList_SET_ITEM(__pyx_t_1, 13, __pyx_n_s_hu_HU);
  __Pyx_INCREF(__pyx_n_s_bg_BG);
  __Pyx_GIVEREF(__pyx_n_s_bg_BG);
  PyList_SET_ITEM(__pyx_t_1, 14, __pyx_n_s_bg_BG);
  __Pyx_INCREF(__pyx_n_s_pt_PT);
  __Pyx_GIVEREF(__pyx_n_s_pt_PT);
  PyList_SET_ITEM(__pyx_t_1, 15, __pyx_n_s_pt_PT);
  __Pyx_INCREF(__pyx_n_s_pt_BR);
  __Pyx_GIVEREF(__pyx_n_s_pt_BR);
  PyList_SET_ITEM(__pyx_t_1, 16, __pyx_n_s_pt_BR);
  __Pyx_INCREF(__pyx_n_s_es_ES);
  __Pyx_GIVEREF(__pyx_n_s_es_ES);
  PyList_SET_ITEM(__pyx_t_1, 17, __pyx_n_s_es_ES);
  __Pyx_INCREF(__pyx_n_s_en_IE);
  __Pyx_GIVEREF(__pyx_n_s_en_IE);
  PyList_SET_ITEM(__pyx_t_1, 18, __pyx_n_s_en_IE);
  __Pyx_INCREF(__pyx_n_s_nl_NL);
  __Pyx_GIVEREF(__pyx_n_s_nl_NL);
  PyList_SET_ITEM(__pyx_t_1, 19, __pyx_n_s_nl_NL);
  __Pyx_INCREF(__pyx_n_s_fr_CH);
  __Pyx_GIVEREF(__pyx_n_s_fr_CH);
  PyList_SET_ITEM(__pyx_t_1, 20, __pyx_n_s_fr_CH);
  __Pyx_INCREF(__pyx_n_s_de_CH);
  __Pyx_GIVEREF(__pyx_n_s_de_CH);
  PyList_SET_ITEM(__pyx_t_1, 21, __pyx_n_s_de_CH);
  __Pyx_INCREF(__pyx_n_s_es_US);
  __Pyx_GIVEREF(__pyx_n_s_es_US);
  PyList_SET_ITEM(__pyx_t_1, 22, __pyx_n_s_es_US);
  __Pyx_INCREF(__pyx_n_s_fr_CA);
  __Pyx_GIVEREF(__pyx_n_s_fr_CA);
  PyList_SET_ITEM(__pyx_t_1, 23, __pyx_n_s_fr_CA);
  __Pyx_INCREF(__pyx_n_s_ru_BY);
  __Pyx_GIVEREF(__pyx_n_s_ru_BY);
  PyList_SET_ITEM(__pyx_t_1, 24, __pyx_n_s_ru_BY);
  __Pyx_INCREF(__pyx_n_s_en_PH);
  __Pyx_GIVEREF(__pyx_n_s_en_PH);
  PyList_SET_ITEM(__pyx_t_1, 25, __pyx_n_s_en_PH);
  __Pyx_INCREF(__pyx_n_s_en_AU);
  __Pyx_GIVEREF(__pyx_n_s_en_AU);
  PyList_SET_ITEM(__pyx_t_1, 26, __pyx_n_s_en_AU);
  __Pyx_INCREF(__pyx_n_s_hy_AM);
  __Pyx_GIVEREF(__pyx_n_s_hy_AM);
  PyList_SET_ITEM(__pyx_t_1, 27, __pyx_n_s_hy_AM);
  __Pyx_INCREF(__pyx_n_s_fa_IR);
  __Pyx_GIVEREF(__pyx_n_s_fa_IR);
  PyList_SET_ITEM(__pyx_t_1, 28, __pyx_n_s_fa_IR);
  __Pyx_INCREF(__pyx_n_s_de_AT);
  __Pyx_GIVEREF(__pyx_n_s_de_AT);
  PyList_SET_ITEM(__pyx_t_1, 29, __pyx_n_s_de_AT);
  __Pyx_INCREF(__pyx_n_s_cs_CZ);
  __Pyx_GIVEREF(__pyx_n_s_cs_CZ);
  PyList_SET_ITEM(__pyx_t_1, 30, __pyx_n_s_cs_CZ);
  __Pyx_INCREF(__pyx_n_s_ru_KZ);
  __Pyx_GIVEREF(__pyx_n_s_ru_KZ);
  PyList_SET_ITEM(__pyx_t_1, 31, __pyx_n_s_ru_KZ);
  __Pyx_INCREF(__pyx_n_s_en_CA);
  __Pyx_GIVEREF(__pyx_n_s_en_CA);
  PyList_SET_ITEM(__pyx_t_1, 32, __pyx_n_s_en_CA);
  __Pyx_INCREF(__pyx_n_s_fr_BE);
  __Pyx_GIVEREF(__pyx_n_s_fr_BE);
  PyList_SET_ITEM(__pyx_t_1, 33, __pyx_n_s_fr_BE);
  __Pyx_INCREF(__pyx_n_s_az_AZ);
  __Pyx_GIVEREF(__pyx_n_s_az_AZ);
  PyList_SET_ITEM(__pyx_t_1, 34, __pyx_n_s_az_AZ);
  __Pyx_INCREF(__pyx_n_s_en_NZ);
  __Pyx_GIVEREF(__pyx_n_s_en_NZ);
  PyList_SET_ITEM(__pyx_t_1, 35, __pyx_n_s_en_NZ);
  __Pyx_INCREF(__pyx_n_s_en_ZA);
  __Pyx_GIVEREF(__pyx_n_s_en_ZA);
  PyList_SET_ITEM(__pyx_t_1, 36, __pyx_n_s_en_ZA);
  __Pyx_INCREF(__pyx_n_s_es_LA);
  __Pyx_GIVEREF(__pyx_n_s_es_LA);
  PyList_SET_ITEM(__pyx_t_1, 37, __pyx_n_s_es_LA);
  __Pyx_INCREF(__pyx_n_s_ru_KG);
  __Pyx_GIVEREF(__pyx_n_s_ru_KG);
  PyList_SET_ITEM(__pyx_t_1, 38, __pyx_n_s_ru_KG);
  __Pyx_INCREF(__pyx_n_s_pl_PL);
  __Pyx_GIVEREF(__pyx_n_s_pl_PL);
  PyList_SET_ITEM(__pyx_t_1, 39, __pyx_n_s_pl_PL);
  __Pyx_INCREF(__pyx_n_s_es_MX);
  __Pyx_GIVEREF(__pyx_n_s_es_MX);
  PyList_SET_ITEM(__pyx_t_1, 40, __pyx_n_s_es_MX);
  __Pyx_INCREF(__pyx_n_s_ro_RO);
  __Pyx_GIVEREF(__pyx_n_s_ro_RO);
  PyList_SET_ITEM(__pyx_t_1, 41, __pyx_n_s_ro_RO);
  __Pyx_INCREF(__pyx_n_s_el_GR);
  __Pyx_GIVEREF(__pyx_n_s_el_GR);
  PyList_SET_ITEM(__pyx_t_1, 42, __pyx_n_s_el_GR);
  __Pyx_INCREF(__pyx_n_s_iw_IL);
  __Pyx_GIVEREF(__pyx_n_s_iw_IL);
  PyList_SET_ITEM(__pyx_t_1, 43, __pyx_n_s_iw_IL);
  __Pyx_INCREF(__pyx_n_s_in_ID);
  __Pyx_GIVEREF(__pyx_n_s_in_ID);
  PyList_SET_ITEM(__pyx_t_1, 44, __pyx_n_s_in_ID);
  __Pyx_INCREF(__pyx_n_s_ga_IE);
  __Pyx_GIVEREF(__pyx_n_s_ga_IE);
  PyList_SET_ITEM(__pyx_t_1, 45, __pyx_n_s_ga_IE);
  __Pyx_INCREF(__pyx_n_s_en_IN);
  __Pyx_GIVEREF(__pyx_n_s_en_IN);
  PyList_SET_ITEM(__pyx_t_1, 46, __pyx_n_s_en_IN);
  __Pyx_INCREF(__pyx_n_s_ar_SA);
  __Pyx_GIVEREF(__pyx_n_s_ar_SA);
  PyList_SET_ITEM(__pyx_t_1, 47, __pyx_n_s_ar_SA);
  __Pyx_INCREF(__pyx_n_s_ka_GE);
  __Pyx_GIVEREF(__pyx_n_s_ka_GE);
  PyList_SET_ITEM(__pyx_t_1, 48, __pyx_n_s_ka_GE);
  __Pyx_INCREF(__pyx_n_s_es_CO);
  __Pyx_GIVEREF(__pyx_n_s_es_CO);
  PyList_SET_ITEM(__pyx_t_1, 49, __pyx_n_s_es_CO);
  __Pyx_INCREF(__pyx_n_s_es_SV);
  __Pyx_GIVEREF(__pyx_n_s_es_SV);
  PyList_SET_ITEM(__pyx_t_1, 50, __pyx_n_s_es_SV);
  __Pyx_INCREF(__pyx_n_s_hr_HR);
  __Pyx_GIVEREF(__pyx_n_s_hr_HR);
  PyList_SET_ITEM(__pyx_t_1, 51, __pyx_n_s_hr_HR);
  __Pyx_INCREF(__pyx_n_s_ar_JO);
  __Pyx_GIVEREF(__pyx_n_s_ar_JO);
  PyList_SET_ITEM(__pyx_t_1, 52, __pyx_n_s_ar_JO);
  __Pyx_INCREF(__pyx_n_s_es_PE);
  __Pyx_GIVEREF(__pyx_n_s_es_PE);
  PyList_SET_ITEM(__pyx_t_1, 53, __pyx_n_s_es_PE);
  __Pyx_INCREF(__pyx_n_s_it_SM);
  __Pyx_GIVEREF(__pyx_n_s_it_SM);
  PyList_SET_ITEM(__pyx_t_1, 54, __pyx_n_s_it_SM);
  __Pyx_INCREF(__pyx_n_s_ar_AR);
  __Pyx_GIVEREF(__pyx_n_s_ar_AR);
  PyList_SET_ITEM(__pyx_t_1, 55, __pyx_n_s_ar_AR);
  __Pyx_INCREF(__pyx_n_s_en_SE);
  __Pyx_GIVEREF(__pyx_n_s_en_SE);
  PyList_SET_ITEM(__pyx_t_1, 56, __pyx_n_s_en_SE);
  __Pyx_INCREF(__pyx_n_s_nb_NO);
  __Pyx_GIVEREF(__pyx_n_s_nb_NO);
  PyList_SET_ITEM(__pyx_t_1, 57, __pyx_n_s_nb_NO);
  __Pyx_INCREF(__pyx_n_s_sk_SK);
  __Pyx_GIVEREF(__pyx_n_s_sk_SK);
  PyList_SET_ITEM(__pyx_t_1, 58, __pyx_n_s_sk_SK);
  __Pyx_INCREF(__pyx_n_s_bs_BA);
  __Pyx_GIVEREF(__pyx_n_s_bs_BA);
  PyList_SET_ITEM(__pyx_t_1, 59, __pyx_n_s_bs_BA);
  __Pyx_INCREF(__pyx_n_s_nl_BE);
  __Pyx_GIVEREF(__pyx_n_s_nl_BE);
  PyList_SET_ITEM(__pyx_t_1, 60, __pyx_n_s_nl_BE);
  __Pyx_INCREF(__pyx_n_s_uz_UZ);
  __Pyx_GIVEREF(__pyx_n_s_uz_UZ);
  PyList_SET_ITEM(__pyx_t_1, 61, __pyx_n_s_uz_UZ);
  __Pyx_INCREF(__pyx_n_s_sl_SI);
  __Pyx_GIVEREF(__pyx_n_s_sl_SI);
  PyList_SET_ITEM(__pyx_t_1, 62, __pyx_n_s_sl_SI);
  __Pyx_INCREF(__pyx_n_s_es_CL);
  __Pyx_GIVEREF(__pyx_n_s_es_CL);
  PyList_SET_ITEM(__pyx_t_1, 63, __pyx_n_s_es_CL);
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_rc);
  __pyx_t_2 = __pyx_cur_scope->__pyx_v_rc; __pyx_t_8 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_8)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_8);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_4 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_8, __pyx_t_1) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_1);
  __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 59, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_locale = __pyx_t_4;
  __pyx_t_4 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_data_ua); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_8 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_s_xyz); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_8, __pyx_n_s_split); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_8)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_8);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_2 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_8, __pyx_kp_s__14) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_s__14);
  __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_rc);
  __pyx_t_1 = __pyx_cur_scope->__pyx_v_rc; __pyx_t_8 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_8)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_8);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_4 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_8, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_2);
  __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_data_ua); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_s_rozh); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_data_ua); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_8 = __Pyx_PyObject_Dict_GetItem(__pyx_t_1, __pyx_n_s_bas); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyList_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_4);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_8);
  PyList_SET_ITEM(__pyx_t_1, 2, __pyx_t_8);
  __pyx_t_4 = 0;
  __pyx_t_2 = 0;
  __pyx_t_8 = 0;
  __pyx_v_merk = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_kp_s_0_0, __pyx_n_s_format); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__15, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__16, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__17, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_3 = NULL;
  __pyx_t_7 = 0;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_8))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_8);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_8, function);
      __pyx_t_7 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_8)) {
    PyObject *__pyx_temp[4] = {__pyx_t_3, __pyx_t_2, __pyx_t_4, __pyx_t_5};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_7, 3+__pyx_t_7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 61, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_8)) {
    PyObject *__pyx_temp[4] = {__pyx_t_3, __pyx_t_2, __pyx_t_4, __pyx_t_5};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_7, 3+__pyx_t_7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 61, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  {
    __pyx_t_6 = PyTuple_New(3+__pyx_t_7); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 61, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_6, 0+__pyx_t_7, __pyx_t_2);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_6, 1+__pyx_t_7, __pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_6, 2+__pyx_t_7, __pyx_t_5);
    __pyx_t_2 = 0;
    __pyx_t_4 = 0;
    __pyx_t_5 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_t_6, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 61, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  }
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_v_versi = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_GetItemInt_List(__pyx_v_merk, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_8 = __Pyx_GetItemInt_List(__pyx_v_merk, 1, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_6 = __Pyx_GetItemInt_List(__pyx_v_merk, 2, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_5 = __Pyx_GetItemInt_List(__pyx_v_merk, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_tipe_dev, __pyx_n_s_split); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_4 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_kp_s__9) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_kp_s__9);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_4, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyTuple_New(12); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_v_andro);
  __Pyx_GIVEREF(__pyx_v_andro);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_v_andro);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_t_1);
  __Pyx_INCREF(__pyx_v_build);
  __Pyx_GIVEREF(__pyx_v_build);
  PyTuple_SET_ITEM(__pyx_t_4, 2, __pyx_v_build);
  __Pyx_INCREF(__pyx_v_versi);
  __Pyx_GIVEREF(__pyx_v_versi);
  PyTuple_SET_ITEM(__pyx_t_4, 3, __pyx_v_versi);
  __Pyx_INCREF(__pyx_v_locale);
  __Pyx_GIVEREF(__pyx_v_locale);
  PyTuple_SET_ITEM(__pyx_t_4, 4, __pyx_v_locale);
  __Pyx_INCREF(__pyx_v_kode);
  __Pyx_GIVEREF(__pyx_v_kode);
  PyTuple_SET_ITEM(__pyx_t_4, 5, __pyx_v_kode);
  __Pyx_INCREF(__pyx_v_fbcr);
  __Pyx_GIVEREF(__pyx_v_fbcr);
  PyTuple_SET_ITEM(__pyx_t_4, 6, __pyx_v_fbcr);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_4, 7, __pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_4, 8, __pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_4, 9, __pyx_t_5);
  __Pyx_INCREF(__pyx_v_andro);
  __Pyx_GIVEREF(__pyx_v_andro);
  PyTuple_SET_ITEM(__pyx_t_4, 10, __pyx_v_andro);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_4, 11, __pyx_t_2);
  __pyx_t_1 = 0;
  __pyx_t_8 = 0;
  __pyx_t_6 = 0;
  __pyx_t_5 = 0;
  __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyString_Format(__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s, __pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_mes_kids = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_GetItemInt_List(__pyx_v_merk, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = __Pyx_GetItemInt_List(__pyx_v_merk, 1, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = __Pyx_GetItemInt_List(__pyx_v_merk, 2, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_GetItemInt_List(__pyx_v_merk, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_tipe_dev, __pyx_n_s_split); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_8 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_3, __pyx_kp_s__9) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_s__9);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_8, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = PyTuple_New(12); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_INCREF(__pyx_v_andro);
  __Pyx_GIVEREF(__pyx_v_andro);
  PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_v_andro);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_2);
  __Pyx_INCREF(__pyx_v_build);
  __Pyx_GIVEREF(__pyx_v_build);
  PyTuple_SET_ITEM(__pyx_t_8, 2, __pyx_v_build);
  __Pyx_INCREF(__pyx_v_versi);
  __Pyx_GIVEREF(__pyx_v_versi);
  PyTuple_SET_ITEM(__pyx_t_8, 3, __pyx_v_versi);
  __Pyx_INCREF(__pyx_v_locale);
  __Pyx_GIVEREF(__pyx_v_locale);
  PyTuple_SET_ITEM(__pyx_t_8, 4, __pyx_v_locale);
  __Pyx_INCREF(__pyx_v_kode);
  __Pyx_GIVEREF(__pyx_v_kode);
  PyTuple_SET_ITEM(__pyx_t_8, 5, __pyx_v_kode);
  __Pyx_INCREF(__pyx_v_fbcr);
  __Pyx_GIVEREF(__pyx_v_fbcr);
  PyTuple_SET_ITEM(__pyx_t_8, 6, __pyx_v_fbcr);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_8, 7, __pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_8, 8, __pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_8, 9, __pyx_t_6);
  __Pyx_INCREF(__pyx_v_andro);
  __Pyx_GIVEREF(__pyx_v_andro);
  PyTuple_SET_ITEM(__pyx_t_8, 10, __pyx_v_andro);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_8, 11, __pyx_t_1);
  __pyx_t_2 = 0;
  __pyx_t_4 = 0;
  __pyx_t_5 = 0;
  __pyx_t_6 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyString_Format(__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s_2, __pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_v_mes_lite = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_GetItemInt_List(__pyx_v_merk, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_8 = __Pyx_GetItemInt_List(__pyx_v_merk, 1, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_6 = __Pyx_GetItemInt_List(__pyx_v_merk, 2, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_5 = __Pyx_GetItemInt_List(__pyx_v_merk, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_tipe_dev, __pyx_n_s_split); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_4 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_kp_s__9) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_kp_s__9);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_4, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyTuple_New(12); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_v_andro);
  __Pyx_GIVEREF(__pyx_v_andro);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_v_andro);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_t_1);
  __Pyx_INCREF(__pyx_v_build);
  __Pyx_GIVEREF(__pyx_v_build);
  PyTuple_SET_ITEM(__pyx_t_4, 2, __pyx_v_build);
  __Pyx_INCREF(__pyx_v_versi);
  __Pyx_GIVEREF(__pyx_v_versi);
  PyTuple_SET_ITEM(__pyx_t_4, 3, __pyx_v_versi);
  __Pyx_INCREF(__pyx_v_locale);
  __Pyx_GIVEREF(__pyx_v_locale);
  PyTuple_SET_ITEM(__pyx_t_4, 4, __pyx_v_locale);
  __Pyx_INCREF(__pyx_v_kode);
  __Pyx_GIVEREF(__pyx_v_kode);
  PyTuple_SET_ITEM(__pyx_t_4, 5, __pyx_v_kode);
  __Pyx_INCREF(__pyx_v_fbcr);
  __Pyx_GIVEREF(__pyx_v_fbcr);
  PyTuple_SET_ITEM(__pyx_t_4, 6, __pyx_v_fbcr);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_4, 7, __pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_4, 8, __pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_4, 9, __pyx_t_5);
  __Pyx_INCREF(__pyx_v_andro);
  __Pyx_GIVEREF(__pyx_v_andro);
  PyTuple_SET_ITEM(__pyx_t_4, 10, __pyx_v_andro);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_4, 11, __pyx_t_2);
  __pyx_t_1 = 0;
  __pyx_t_8 = 0;
  __pyx_t_6 = 0;
  __pyx_t_5 = 0;
  __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyString_Format(__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s_3, __pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_fb_ori = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_GetItemInt_List(__pyx_v_merk, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = __Pyx_GetItemInt_List(__pyx_v_merk, 1, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = __Pyx_GetItemInt_List(__pyx_v_merk, 2, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_GetItemInt_List(__pyx_v_merk, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_tipe_dev, __pyx_n_s_split); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_8 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_3, __pyx_kp_s__9) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_s__9);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_8, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__18, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_3 = PyTuple_New(13); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_v_andro);
  __Pyx_GIVEREF(__pyx_v_andro);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_v_andro);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_2);
  __Pyx_INCREF(__pyx_v_build);
  __Pyx_GIVEREF(__pyx_v_build);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_v_build);
  __Pyx_INCREF(__pyx_v_versi);
  __Pyx_GIVEREF(__pyx_v_versi);
  PyTuple_SET_ITEM(__pyx_t_3, 3, __pyx_v_versi);
  __Pyx_INCREF(__pyx_v_locale);
  __Pyx_GIVEREF(__pyx_v_locale);
  PyTuple_SET_ITEM(__pyx_t_3, 4, __pyx_v_locale);
  __Pyx_INCREF(__pyx_v_kode);
  __Pyx_GIVEREF(__pyx_v_kode);
  PyTuple_SET_ITEM(__pyx_t_3, 5, __pyx_v_kode);
  __Pyx_INCREF(__pyx_v_fbcr);
  __Pyx_GIVEREF(__pyx_v_fbcr);
  PyTuple_SET_ITEM(__pyx_t_3, 6, __pyx_v_fbcr);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_3, 7, __pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_3, 8, __pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_3, 9, __pyx_t_6);
  __Pyx_INCREF(__pyx_v_andro);
  __Pyx_GIVEREF(__pyx_v_andro);
  PyTuple_SET_ITEM(__pyx_t_3, 10, __pyx_v_andro);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 11, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_3, 12, __pyx_t_8);
  __pyx_t_2 = 0;
  __pyx_t_4 = 0;
  __pyx_t_5 = 0;
  __pyx_t_6 = 0;
  __pyx_t_1 = 0;
  __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyString_Format(__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s_4, __pyx_t_3); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_mes_ori = ((PyObject*)__pyx_t_8);
  __pyx_t_8 = 0;

  
  __pyx_t_8 = __Pyx_GetItemInt_List(__pyx_v_merk, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_3 = __Pyx_GetItemInt_List(__pyx_v_merk, 0, long, 1, __Pyx_PyInt_From_long, 1, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_6 = PyList_New(4); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_INCREF(__pyx_n_s_WIFI);
  __Pyx_GIVEREF(__pyx_n_s_WIFI);
  PyList_SET_ITEM(__pyx_t_6, 0, __pyx_n_s_WIFI);
  __Pyx_INCREF(__pyx_kp_s_4G);
  __Pyx_GIVEREF(__pyx_kp_s_4G);
  PyList_SET_ITEM(__pyx_t_6, 1, __pyx_kp_s_4G);
  __Pyx_INCREF(__pyx_kp_s_5G);
  __Pyx_GIVEREF(__pyx_kp_s_5G);
  PyList_SET_ITEM(__pyx_t_6, 2, __pyx_kp_s_5G);
  __Pyx_INCREF(__pyx_kp_s_3G);
  __Pyx_GIVEREF(__pyx_kp_s_3G);
  PyList_SET_ITEM(__pyx_t_6, 3, __pyx_kp_s_3G);
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_rc);
  __pyx_t_5 = __pyx_cur_scope->__pyx_v_rc; __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_4, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_6);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyTuple_New(8); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_INCREF(__pyx_v_andro);
  __Pyx_GIVEREF(__pyx_v_andro);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_v_andro);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_8);
  __Pyx_INCREF(__pyx_v_build);
  __Pyx_GIVEREF(__pyx_v_build);
  PyTuple_SET_ITEM(__pyx_t_5, 2, __pyx_v_build);
  __Pyx_INCREF(__pyx_v_kode);
  __Pyx_GIVEREF(__pyx_v_kode);
  PyTuple_SET_ITEM(__pyx_t_5, 3, __pyx_v_kode);
  __Pyx_INCREF(__pyx_v_versi);
  __Pyx_GIVEREF(__pyx_v_versi);
  PyTuple_SET_ITEM(__pyx_t_5, 4, __pyx_v_versi);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_5, 5, __pyx_t_3);
  __Pyx_INCREF(__pyx_v_locale);
  __Pyx_GIVEREF(__pyx_v_locale);
  PyTuple_SET_ITEM(__pyx_t_5, 6, __pyx_v_locale);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_5, 7, __pyx_t_1);
  __pyx_t_8 = 0;
  __pyx_t_3 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyString_Format(__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s_5, __pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 66, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_v_fb_lite = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_9 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_ua_mes, __pyx_v_value, Py_EQ)); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 67, __pyx_L1_error)
  __pyx_t_10 = (__pyx_t_9 != 0);
  if (__pyx_t_10) {

    
    __Pyx_XDECREF(__pyx_r);
    __pyx_t_5 = PyList_New(3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 68, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_INCREF(__pyx_v_mes_kids);
    __Pyx_GIVEREF(__pyx_v_mes_kids);
    PyList_SET_ITEM(__pyx_t_5, 0, __pyx_v_mes_kids);
    __Pyx_INCREF(__pyx_v_mes_lite);
    __Pyx_GIVEREF(__pyx_v_mes_lite);
    PyList_SET_ITEM(__pyx_t_5, 1, __pyx_v_mes_lite);
    __Pyx_INCREF(__pyx_v_mes_ori);
    __Pyx_GIVEREF(__pyx_v_mes_ori);
    PyList_SET_ITEM(__pyx_t_5, 2, __pyx_v_mes_ori);
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_rc);
    __pyx_t_3 = __pyx_cur_scope->__pyx_v_rc; __pyx_t_8 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_8)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_8);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_1 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_8, __pyx_t_5) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_5);
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 68, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_r = __pyx_t_1;
    __pyx_t_1 = 0;
    goto __pyx_L0;

    
  }

  
  __pyx_t_10 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_ua_ori, __pyx_v_value, Py_EQ)); if (unlikely(__pyx_t_10 < 0)) __PYX_ERR(0, 69, __pyx_L1_error)
  __pyx_t_9 = (__pyx_t_10 != 0);
  if (__pyx_t_9) {

    
    __Pyx_XDECREF(__pyx_r);
    __pyx_t_3 = PyList_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 70, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_INCREF(__pyx_v_fb_lite);
    __Pyx_GIVEREF(__pyx_v_fb_lite);
    PyList_SET_ITEM(__pyx_t_3, 0, __pyx_v_fb_lite);
    __Pyx_INCREF(__pyx_v_fb_ori);
    __Pyx_GIVEREF(__pyx_v_fb_ori);
    PyList_SET_ITEM(__pyx_t_3, 1, __pyx_v_fb_ori);
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_rc);
    __pyx_t_5 = __pyx_cur_scope->__pyx_v_rc; __pyx_t_8 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_8)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_8);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_1 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_8, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_3);
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 70, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_r = __pyx_t_1;
    __pyx_t_1 = 0;
    goto __pyx_L0;

    
  }

  
   {
    __Pyx_XDECREF(__pyx_r);
    __pyx_t_5 = PyList_New(5); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 72, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_INCREF(__pyx_v_mes_kids);
    __Pyx_GIVEREF(__pyx_v_mes_kids);
    PyList_SET_ITEM(__pyx_t_5, 0, __pyx_v_mes_kids);
    __Pyx_INCREF(__pyx_v_mes_lite);
    __Pyx_GIVEREF(__pyx_v_mes_lite);
    PyList_SET_ITEM(__pyx_t_5, 1, __pyx_v_mes_lite);
    __Pyx_INCREF(__pyx_v_mes_ori);
    __Pyx_GIVEREF(__pyx_v_mes_ori);
    PyList_SET_ITEM(__pyx_t_5, 2, __pyx_v_mes_ori);
    __Pyx_INCREF(__pyx_v_fb_lite);
    __Pyx_GIVEREF(__pyx_v_fb_lite);
    PyList_SET_ITEM(__pyx_t_5, 3, __pyx_v_fb_lite);
    __Pyx_INCREF(__pyx_v_fb_ori);
    __Pyx_GIVEREF(__pyx_v_fb_ori);
    PyList_SET_ITEM(__pyx_t_5, 4, __pyx_v_fb_ori);
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_rc);
    __pyx_t_3 = __pyx_cur_scope->__pyx_v_rc; __pyx_t_8 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_8)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_8);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_1 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_8, __pyx_t_5) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_5);
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 72, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_r = __pyx_t_1;
    __pyx_t_1 = 0;
    goto __pyx_L0;
  }

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("menu.ua_api", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_rr);
  __Pyx_XDECREF(__pyx_v_andro);
  __Pyx_XDECREF(__pyx_v_build);
  __Pyx_XDECREF(__pyx_v_tipe_dev);
  __Pyx_XDECREF(__pyx_v_fbcr);
  __Pyx_XDECREF(__pyx_v_kode);
  __Pyx_XDECREF(__pyx_v_locale);
  __Pyx_XDECREF(__pyx_v_merk);
  __Pyx_XDECREF(__pyx_v_versi);
  __Pyx_XDECREF(__pyx_v_mes_kids);
  __Pyx_XDECREF(__pyx_v_mes_lite);
  __Pyx_XDECREF(__pyx_v_fb_ori);
  __Pyx_XDECREF(__pyx_v_mes_ori);
  __Pyx_XDECREF(__pyx_v_fb_lite);
  __Pyx_XDECREF(__pyx_gb_4menu_6ua_api_2generator);
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4menu_9api_ios(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); 
static PyMethodDef __pyx_mdef_4menu_9api_ios = {"api_ios", (PyCFunction)__pyx_pw_4menu_9api_ios, METH_NOARGS, 0};
static PyObject *__pyx_pw_4menu_9api_ios(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("api_ios (wrapper)", 0);
  __pyx_r = __pyx_pf_4menu_8api_ios(__pyx_self);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4menu_7api_ios_2generator1(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 



static PyObject *__pyx_pf_4menu_7api_ios_genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr *)__pyx_tp_new_4menu___pyx_scope_struct_3_genexpr(__pyx_ptype_4menu___pyx_scope_struct_3_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 77, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4menu_7api_ios_2generator1, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_api_ios_locals_genexpr, __pyx_n_s_menu); if (unlikely(!gen)) __PYX_ERR(0, 77, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("menu.api_ios.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4menu_7api_ios_2generator1(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  long __pyx_t_1;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L6_resume_from_yield;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 77, __pyx_L1_error)
  for (__pyx_t_1 = 0; __pyx_t_1 < 9; __pyx_t_1+=1) {
    __pyx_cur_scope->__pyx_v_z = __pyx_t_1;
    if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_rc)) { __Pyx_RaiseClosureNameError("rc"); __PYX_ERR(0, 77, __pyx_L1_error) }
    __Pyx_INCREF(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_rc);
    __pyx_t_3 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_rc; __pyx_t_4 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_4)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_4);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_2 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_4, __pyx_kp_s_1234567890) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_kp_s_1234567890);
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 77, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_r = __pyx_t_2;
    __pyx_t_2 = 0;
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_1;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L6_resume_from_yield:;
    __pyx_t_1 = __pyx_cur_scope->__pyx_t_0;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 77, __pyx_L1_error)
  }
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4menu_7api_ios_5generator2(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 



static PyObject *__pyx_pf_4menu_7api_ios_3genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr *)__pyx_tp_new_4menu___pyx_scope_struct_4_genexpr(__pyx_ptype_4menu___pyx_scope_struct_4_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 82, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4menu_7api_ios_5generator2, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_api_ios_locals_genexpr, __pyx_n_s_menu); if (unlikely(!gen)) __PYX_ERR(0, 82, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("menu.api_ios.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4menu_7api_ios_5generator2(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L6_resume_from_yield;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 82, __pyx_L1_error)
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone)) { __Pyx_RaiseClosureNameError("iphone"); __PYX_ERR(0, 82, __pyx_L1_error) }
  if (unlikely(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
    __PYX_ERR(0, 82, __pyx_L1_error)
  }
  __pyx_t_1 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
  for (;;) {
    if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_3 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_3); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 82, __pyx_L1_error)
    #else
    __pyx_t_3 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 82, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    #endif
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_x);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_x, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_x);
    __pyx_r = __pyx_cur_scope->__pyx_v_x;
    __Pyx_XGIVEREF(__pyx_t_1);
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_1;
    __pyx_cur_scope->__pyx_t_1 = __pyx_t_2;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L6_resume_from_yield:;
    __pyx_t_1 = __pyx_cur_scope->__pyx_t_0;
    __pyx_cur_scope->__pyx_t_0 = 0;
    __Pyx_XGOTREF(__pyx_t_1);
    __pyx_t_2 = __pyx_cur_scope->__pyx_t_1;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 82, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4menu_7api_ios_8generator3(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 

static PyObject *__pyx_pf_4menu_7api_ios_6genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr *)__pyx_tp_new_4menu___pyx_scope_struct_5_genexpr(__pyx_ptype_4menu___pyx_scope_struct_5_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 82, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4menu_7api_ios_8generator3, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_api_ios_locals_genexpr, __pyx_n_s_menu); if (unlikely(!gen)) __PYX_ERR(0, 82, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("menu.api_ios.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4menu_7api_ios_8generator3(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L6_resume_from_yield;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 82, __pyx_L1_error)
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone)) { __Pyx_RaiseClosureNameError("iphone"); __PYX_ERR(0, 82, __pyx_L1_error) }
  if (unlikely(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
    __PYX_ERR(0, 82, __pyx_L1_error)
  }
  __pyx_t_1 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
  for (;;) {
    if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_3 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_3); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 82, __pyx_L1_error)
    #else
    __pyx_t_3 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 82, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    #endif
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_x);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_x, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_x);
    __pyx_r = __pyx_cur_scope->__pyx_v_x;
    __Pyx_XGIVEREF(__pyx_t_1);
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_1;
    __pyx_cur_scope->__pyx_t_1 = __pyx_t_2;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L6_resume_from_yield:;
    __pyx_t_1 = __pyx_cur_scope->__pyx_t_0;
    __pyx_cur_scope->__pyx_t_0 = 0;
    __Pyx_XGOTREF(__pyx_t_1);
    __pyx_t_2 = __pyx_cur_scope->__pyx_t_1;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 82, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4menu_7api_ios_11generator4(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 



static PyObject *__pyx_pf_4menu_7api_ios_9genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr *)__pyx_tp_new_4menu___pyx_scope_struct_6_genexpr(__pyx_ptype_4menu___pyx_scope_struct_6_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 83, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4menu_7api_ios_11generator4, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_api_ios_locals_genexpr, __pyx_n_s_menu); if (unlikely(!gen)) __PYX_ERR(0, 83, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("menu.api_ios.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4menu_7api_ios_11generator4(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L6_resume_from_yield;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 83, __pyx_L1_error)
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone)) { __Pyx_RaiseClosureNameError("iphone"); __PYX_ERR(0, 83, __pyx_L1_error) }
  if (unlikely(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
    __PYX_ERR(0, 83, __pyx_L1_error)
  }
  __pyx_t_1 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
  for (;;) {
    if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_3 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_3); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 83, __pyx_L1_error)
    #else
    __pyx_t_3 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 83, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    #endif
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_x);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_x, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_x);
    __pyx_r = __pyx_cur_scope->__pyx_v_x;
    __Pyx_XGIVEREF(__pyx_t_1);
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_1;
    __pyx_cur_scope->__pyx_t_1 = __pyx_t_2;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L6_resume_from_yield:;
    __pyx_t_1 = __pyx_cur_scope->__pyx_t_0;
    __pyx_cur_scope->__pyx_t_0 = 0;
    __Pyx_XGOTREF(__pyx_t_1);
    __pyx_t_2 = __pyx_cur_scope->__pyx_t_1;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 83, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4menu_7api_ios_14generator5(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 

static PyObject *__pyx_pf_4menu_7api_ios_12genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr *)__pyx_tp_new_4menu___pyx_scope_struct_7_genexpr(__pyx_ptype_4menu___pyx_scope_struct_7_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 83, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4menu_7api_ios_14generator5, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_api_ios_locals_genexpr, __pyx_n_s_menu); if (unlikely(!gen)) __PYX_ERR(0, 83, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("menu.api_ios.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4menu_7api_ios_14generator5(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L6_resume_from_yield;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 83, __pyx_L1_error)
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone)) { __Pyx_RaiseClosureNameError("iphone"); __PYX_ERR(0, 83, __pyx_L1_error) }
  if (unlikely(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
    __PYX_ERR(0, 83, __pyx_L1_error)
  }
  __pyx_t_1 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
  for (;;) {
    if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_3 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_3); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 83, __pyx_L1_error)
    #else
    __pyx_t_3 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 83, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    #endif
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_x);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_x, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_x);
    __pyx_r = __pyx_cur_scope->__pyx_v_x;
    __Pyx_XGIVEREF(__pyx_t_1);
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_1;
    __pyx_cur_scope->__pyx_t_1 = __pyx_t_2;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L6_resume_from_yield:;
    __pyx_t_1 = __pyx_cur_scope->__pyx_t_0;
    __pyx_cur_scope->__pyx_t_0 = 0;
    __Pyx_XGOTREF(__pyx_t_1);
    __pyx_t_2 = __pyx_cur_scope->__pyx_t_1;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 83, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4menu_7api_ios_17generator6(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 



static PyObject *__pyx_pf_4menu_7api_ios_15genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr *)__pyx_tp_new_4menu___pyx_scope_struct_8_genexpr(__pyx_ptype_4menu___pyx_scope_struct_8_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 84, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4menu_7api_ios_17generator6, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_api_ios_locals_genexpr, __pyx_n_s_menu); if (unlikely(!gen)) __PYX_ERR(0, 84, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("menu.api_ios.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4menu_7api_ios_17generator6(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L6_resume_from_yield;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 84, __pyx_L1_error)
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone)) { __Pyx_RaiseClosureNameError("iphone"); __PYX_ERR(0, 84, __pyx_L1_error) }
  if (unlikely(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
    __PYX_ERR(0, 84, __pyx_L1_error)
  }
  __pyx_t_1 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
  for (;;) {
    if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_3 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_3); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 84, __pyx_L1_error)
    #else
    __pyx_t_3 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 84, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    #endif
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_x);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_x, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_x);
    __pyx_r = __pyx_cur_scope->__pyx_v_x;
    __Pyx_XGIVEREF(__pyx_t_1);
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_1;
    __pyx_cur_scope->__pyx_t_1 = __pyx_t_2;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L6_resume_from_yield:;
    __pyx_t_1 = __pyx_cur_scope->__pyx_t_0;
    __pyx_cur_scope->__pyx_t_0 = 0;
    __Pyx_XGOTREF(__pyx_t_1);
    __pyx_t_2 = __pyx_cur_scope->__pyx_t_1;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 84, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4menu_7api_ios_20generator7(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 

static PyObject *__pyx_pf_4menu_7api_ios_18genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr *)__pyx_tp_new_4menu___pyx_scope_struct_9_genexpr(__pyx_ptype_4menu___pyx_scope_struct_9_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 84, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4menu_7api_ios_20generator7, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_api_ios_locals_genexpr, __pyx_n_s_menu); if (unlikely(!gen)) __PYX_ERR(0, 84, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("menu.api_ios.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4menu_7api_ios_20generator7(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L6_resume_from_yield;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 84, __pyx_L1_error)
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone)) { __Pyx_RaiseClosureNameError("iphone"); __PYX_ERR(0, 84, __pyx_L1_error) }
  if (unlikely(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
    __PYX_ERR(0, 84, __pyx_L1_error)
  }
  __pyx_t_1 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
  for (;;) {
    if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_3 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_3); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 84, __pyx_L1_error)
    #else
    __pyx_t_3 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 84, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    #endif
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_x);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_x, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_x);
    __pyx_r = __pyx_cur_scope->__pyx_v_x;
    __Pyx_XGIVEREF(__pyx_t_1);
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_1;
    __pyx_cur_scope->__pyx_t_1 = __pyx_t_2;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L6_resume_from_yield:;
    __pyx_t_1 = __pyx_cur_scope->__pyx_t_0;
    __pyx_cur_scope->__pyx_t_0 = 0;
    __Pyx_XGOTREF(__pyx_t_1);
    __pyx_t_2 = __pyx_cur_scope->__pyx_t_1;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 84, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4menu_7api_ios_23generator8(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 



static PyObject *__pyx_pf_4menu_7api_ios_21genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr *)__pyx_tp_new_4menu___pyx_scope_struct_10_genexpr(__pyx_ptype_4menu___pyx_scope_struct_10_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 85, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4menu_7api_ios_23generator8, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_api_ios_locals_genexpr, __pyx_n_s_menu); if (unlikely(!gen)) __PYX_ERR(0, 85, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("menu.api_ios.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4menu_7api_ios_23generator8(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L6_resume_from_yield;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 85, __pyx_L1_error)
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone)) { __Pyx_RaiseClosureNameError("iphone"); __PYX_ERR(0, 85, __pyx_L1_error) }
  if (unlikely(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
    __PYX_ERR(0, 85, __pyx_L1_error)
  }
  __pyx_t_1 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
  for (;;) {
    if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_3 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_3); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 85, __pyx_L1_error)
    #else
    __pyx_t_3 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 85, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    #endif
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_x);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_x, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_x);
    __pyx_r = __pyx_cur_scope->__pyx_v_x;
    __Pyx_XGIVEREF(__pyx_t_1);
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_1;
    __pyx_cur_scope->__pyx_t_1 = __pyx_t_2;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L6_resume_from_yield:;
    __pyx_t_1 = __pyx_cur_scope->__pyx_t_0;
    __pyx_cur_scope->__pyx_t_0 = 0;
    __Pyx_XGOTREF(__pyx_t_1);
    __pyx_t_2 = __pyx_cur_scope->__pyx_t_1;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 85, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_4menu_7api_ios_26generator9(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 

static PyObject *__pyx_pf_4menu_7api_ios_24genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr *)__pyx_tp_new_4menu___pyx_scope_struct_11_genexpr(__pyx_ptype_4menu___pyx_scope_struct_11_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 85, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_4menu_7api_ios_26generator9, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_api_ios_locals_genexpr, __pyx_n_s_menu); if (unlikely(!gen)) __PYX_ERR(0, 85, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("menu.api_ios.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_4menu_7api_ios_26generator9(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr *__pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L6_resume_from_yield;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 85, __pyx_L1_error)
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone)) { __Pyx_RaiseClosureNameError("iphone"); __PYX_ERR(0, 85, __pyx_L1_error) }
  if (unlikely(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
    __PYX_ERR(0, 85, __pyx_L1_error)
  }
  __pyx_t_1 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_iphone; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
  for (;;) {
    if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_3 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_3); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 85, __pyx_L1_error)
    #else
    __pyx_t_3 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 85, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    #endif
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_x);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_x, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_x);
    __pyx_r = __pyx_cur_scope->__pyx_v_x;
    __Pyx_XGIVEREF(__pyx_t_1);
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_1;
    __pyx_cur_scope->__pyx_t_1 = __pyx_t_2;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L6_resume_from_yield:;
    __pyx_t_1 = __pyx_cur_scope->__pyx_t_0;
    __pyx_cur_scope->__pyx_t_0 = 0;
    __Pyx_XGOTREF(__pyx_t_1);
    __pyx_t_2 = __pyx_cur_scope->__pyx_t_1;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 85, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_4menu_8api_ios(CYTHON_UNUSED PyObject *__pyx_self) {
  struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *__pyx_cur_scope;
  PyObject *__pyx_v_rr = NULL;
  PyObject *__pyx_v_kode = NULL;
  PyObject *__pyx_v_locale = NULL;
  PyObject *__pyx_v_versi = NULL;
  PyObject *__pyx_v_fbcr = NULL;
  PyObject *__pyx_v_ios_ = NULL;
  PyObject *__pyx_v_for_ios = NULL;
  PyObject *__pyx_v_mes_ios = NULL;
  PyObject *__pyx_v_mes_lite_ios = NULL;
  PyObject *__pyx_gb_4menu_7api_ios_2generator1 = 0;
  PyObject *__pyx_gb_4menu_7api_ios_5generator2 = 0;
  PyObject *__pyx_gb_4menu_7api_ios_8generator3 = 0;
  PyObject *__pyx_gb_4menu_7api_ios_11generator4 = 0;
  PyObject *__pyx_gb_4menu_7api_ios_14generator5 = 0;
  PyObject *__pyx_gb_4menu_7api_ios_17generator6 = 0;
  PyObject *__pyx_gb_4menu_7api_ios_20generator7 = 0;
  PyObject *__pyx_gb_4menu_7api_ios_23generator8 = 0;
  PyObject *__pyx_gb_4menu_7api_ios_26generator9 = 0;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("api_ios", 0);
  __pyx_cur_scope = (struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *)__pyx_tp_new_4menu___pyx_scope_struct_2_api_ios(__pyx_ptype_4menu___pyx_scope_struct_2_api_ios, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 75, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_random); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_randint); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_rr = __pyx_t_2;
  __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_random); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_choice); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_cur_scope->__pyx_v_rc = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __pyx_pf_4menu_7api_ios_genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 77, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyString_Join(__pyx_kp_s__12, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 77, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_kode = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;

  
  __pyx_t_1 = PyList_New(64); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 78, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_ru_RU);
  __Pyx_GIVEREF(__pyx_n_s_ru_RU);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_ru_RU);
  __Pyx_INCREF(__pyx_n_s_en_GB);
  __Pyx_GIVEREF(__pyx_n_s_en_GB);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_s_en_GB);
  __Pyx_INCREF(__pyx_n_s_uk_UA);
  __Pyx_GIVEREF(__pyx_n_s_uk_UA);
  PyList_SET_ITEM(__pyx_t_1, 2, __pyx_n_s_uk_UA);
  __Pyx_INCREF(__pyx_n_s_en_US);
  __Pyx_GIVEREF(__pyx_n_s_en_US);
  PyList_SET_ITEM(__pyx_t_1, 3, __pyx_n_s_en_US);
  __Pyx_INCREF(__pyx_n_s_de_DE);
  __Pyx_GIVEREF(__pyx_n_s_de_DE);
  PyList_SET_ITEM(__pyx_t_1, 4, __pyx_n_s_de_DE);
  __Pyx_INCREF(__pyx_n_s_it_IT);
  __Pyx_GIVEREF(__pyx_n_s_it_IT);
  PyList_SET_ITEM(__pyx_t_1, 5, __pyx_n_s_it_IT);
  __Pyx_INCREF(__pyx_n_s_ru_UA);
  __Pyx_GIVEREF(__pyx_n_s_ru_UA);
  PyList_SET_ITEM(__pyx_t_1, 6, __pyx_n_s_ru_UA);
  __Pyx_INCREF(__pyx_n_s_ar_AE);
  __Pyx_GIVEREF(__pyx_n_s_ar_AE);
  PyList_SET_ITEM(__pyx_t_1, 7, __pyx_n_s_ar_AE);
  __Pyx_INCREF(__pyx_n_s_tr_TR);
  __Pyx_GIVEREF(__pyx_n_s_tr_TR);
  PyList_SET_ITEM(__pyx_t_1, 8, __pyx_n_s_tr_TR);
  __Pyx_INCREF(__pyx_n_s_lv_LV);
  __Pyx_GIVEREF(__pyx_n_s_lv_LV);
  PyList_SET_ITEM(__pyx_t_1, 9, __pyx_n_s_lv_LV);
  __Pyx_INCREF(__pyx_n_s_th_TH);
  __Pyx_GIVEREF(__pyx_n_s_th_TH);
  PyList_SET_ITEM(__pyx_t_1, 10, __pyx_n_s_th_TH);
  __Pyx_INCREF(__pyx_n_s_fr_FR);
  __Pyx_GIVEREF(__pyx_n_s_fr_FR);
  PyList_SET_ITEM(__pyx_t_1, 11, __pyx_n_s_fr_FR);
  __Pyx_INCREF(__pyx_n_s_sr_RS);
  __Pyx_GIVEREF(__pyx_n_s_sr_RS);
  PyList_SET_ITEM(__pyx_t_1, 12, __pyx_n_s_sr_RS);
  __Pyx_INCREF(__pyx_n_s_hu_HU);
  __Pyx_GIVEREF(__pyx_n_s_hu_HU);
  PyList_SET_ITEM(__pyx_t_1, 13, __pyx_n_s_hu_HU);
  __Pyx_INCREF(__pyx_n_s_bg_BG);
  __Pyx_GIVEREF(__pyx_n_s_bg_BG);
  PyList_SET_ITEM(__pyx_t_1, 14, __pyx_n_s_bg_BG);
  __Pyx_INCREF(__pyx_n_s_pt_PT);
  __Pyx_GIVEREF(__pyx_n_s_pt_PT);
  PyList_SET_ITEM(__pyx_t_1, 15, __pyx_n_s_pt_PT);
  __Pyx_INCREF(__pyx_n_s_pt_BR);
  __Pyx_GIVEREF(__pyx_n_s_pt_BR);
  PyList_SET_ITEM(__pyx_t_1, 16, __pyx_n_s_pt_BR);
  __Pyx_INCREF(__pyx_n_s_es_ES);
  __Pyx_GIVEREF(__pyx_n_s_es_ES);
  PyList_SET_ITEM(__pyx_t_1, 17, __pyx_n_s_es_ES);
  __Pyx_INCREF(__pyx_n_s_en_IE);
  __Pyx_GIVEREF(__pyx_n_s_en_IE);
  PyList_SET_ITEM(__pyx_t_1, 18, __pyx_n_s_en_IE);
  __Pyx_INCREF(__pyx_n_s_nl_NL);
  __Pyx_GIVEREF(__pyx_n_s_nl_NL);
  PyList_SET_ITEM(__pyx_t_1, 19, __pyx_n_s_nl_NL);
  __Pyx_INCREF(__pyx_n_s_fr_CH);
  __Pyx_GIVEREF(__pyx_n_s_fr_CH);
  PyList_SET_ITEM(__pyx_t_1, 20, __pyx_n_s_fr_CH);
  __Pyx_INCREF(__pyx_n_s_de_CH);
  __Pyx_GIVEREF(__pyx_n_s_de_CH);
  PyList_SET_ITEM(__pyx_t_1, 21, __pyx_n_s_de_CH);
  __Pyx_INCREF(__pyx_n_s_es_US);
  __Pyx_GIVEREF(__pyx_n_s_es_US);
  PyList_SET_ITEM(__pyx_t_1, 22, __pyx_n_s_es_US);
  __Pyx_INCREF(__pyx_n_s_fr_CA);
  __Pyx_GIVEREF(__pyx_n_s_fr_CA);
  PyList_SET_ITEM(__pyx_t_1, 23, __pyx_n_s_fr_CA);
  __Pyx_INCREF(__pyx_n_s_ru_BY);
  __Pyx_GIVEREF(__pyx_n_s_ru_BY);
  PyList_SET_ITEM(__pyx_t_1, 24, __pyx_n_s_ru_BY);
  __Pyx_INCREF(__pyx_n_s_en_PH);
  __Pyx_GIVEREF(__pyx_n_s_en_PH);
  PyList_SET_ITEM(__pyx_t_1, 25, __pyx_n_s_en_PH);
  __Pyx_INCREF(__pyx_n_s_en_AU);
  __Pyx_GIVEREF(__pyx_n_s_en_AU);
  PyList_SET_ITEM(__pyx_t_1, 26, __pyx_n_s_en_AU);
  __Pyx_INCREF(__pyx_n_s_hy_AM);
  __Pyx_GIVEREF(__pyx_n_s_hy_AM);
  PyList_SET_ITEM(__pyx_t_1, 27, __pyx_n_s_hy_AM);
  __Pyx_INCREF(__pyx_n_s_fa_IR);
  __Pyx_GIVEREF(__pyx_n_s_fa_IR);
  PyList_SET_ITEM(__pyx_t_1, 28, __pyx_n_s_fa_IR);
  __Pyx_INCREF(__pyx_n_s_de_AT);
  __Pyx_GIVEREF(__pyx_n_s_de_AT);
  PyList_SET_ITEM(__pyx_t_1, 29, __pyx_n_s_de_AT);
  __Pyx_INCREF(__pyx_n_s_cs_CZ);
  __Pyx_GIVEREF(__pyx_n_s_cs_CZ);
  PyList_SET_ITEM(__pyx_t_1, 30, __pyx_n_s_cs_CZ);
  __Pyx_INCREF(__pyx_n_s_ru_KZ);
  __Pyx_GIVEREF(__pyx_n_s_ru_KZ);
  PyList_SET_ITEM(__pyx_t_1, 31, __pyx_n_s_ru_KZ);
  __Pyx_INCREF(__pyx_n_s_en_CA);
  __Pyx_GIVEREF(__pyx_n_s_en_CA);
  PyList_SET_ITEM(__pyx_t_1, 32, __pyx_n_s_en_CA);
  __Pyx_INCREF(__pyx_n_s_fr_BE);
  __Pyx_GIVEREF(__pyx_n_s_fr_BE);
  PyList_SET_ITEM(__pyx_t_1, 33, __pyx_n_s_fr_BE);
  __Pyx_INCREF(__pyx_n_s_az_AZ);
  __Pyx_GIVEREF(__pyx_n_s_az_AZ);
  PyList_SET_ITEM(__pyx_t_1, 34, __pyx_n_s_az_AZ);
  __Pyx_INCREF(__pyx_n_s_en_NZ);
  __Pyx_GIVEREF(__pyx_n_s_en_NZ);
  PyList_SET_ITEM(__pyx_t_1, 35, __pyx_n_s_en_NZ);
  __Pyx_INCREF(__pyx_n_s_en_ZA);
  __Pyx_GIVEREF(__pyx_n_s_en_ZA);
  PyList_SET_ITEM(__pyx_t_1, 36, __pyx_n_s_en_ZA);
  __Pyx_INCREF(__pyx_n_s_es_LA);
  __Pyx_GIVEREF(__pyx_n_s_es_LA);
  PyList_SET_ITEM(__pyx_t_1, 37, __pyx_n_s_es_LA);
  __Pyx_INCREF(__pyx_n_s_ru_KG);
  __Pyx_GIVEREF(__pyx_n_s_ru_KG);
  PyList_SET_ITEM(__pyx_t_1, 38, __pyx_n_s_ru_KG);
  __Pyx_INCREF(__pyx_n_s_pl_PL);
  __Pyx_GIVEREF(__pyx_n_s_pl_PL);
  PyList_SET_ITEM(__pyx_t_1, 39, __pyx_n_s_pl_PL);
  __Pyx_INCREF(__pyx_n_s_es_MX);
  __Pyx_GIVEREF(__pyx_n_s_es_MX);
  PyList_SET_ITEM(__pyx_t_1, 40, __pyx_n_s_es_MX);
  __Pyx_INCREF(__pyx_n_s_ro_RO);
  __Pyx_GIVEREF(__pyx_n_s_ro_RO);
  PyList_SET_ITEM(__pyx_t_1, 41, __pyx_n_s_ro_RO);
  __Pyx_INCREF(__pyx_n_s_el_GR);
  __Pyx_GIVEREF(__pyx_n_s_el_GR);
  PyList_SET_ITEM(__pyx_t_1, 42, __pyx_n_s_el_GR);
  __Pyx_INCREF(__pyx_n_s_iw_IL);
  __Pyx_GIVEREF(__pyx_n_s_iw_IL);
  PyList_SET_ITEM(__pyx_t_1, 43, __pyx_n_s_iw_IL);
  __Pyx_INCREF(__pyx_n_s_in_ID);
  __Pyx_GIVEREF(__pyx_n_s_in_ID);
  PyList_SET_ITEM(__pyx_t_1, 44, __pyx_n_s_in_ID);
  __Pyx_INCREF(__pyx_n_s_ga_IE);
  __Pyx_GIVEREF(__pyx_n_s_ga_IE);
  PyList_SET_ITEM(__pyx_t_1, 45, __pyx_n_s_ga_IE);
  __Pyx_INCREF(__pyx_n_s_en_IN);
  __Pyx_GIVEREF(__pyx_n_s_en_IN);
  PyList_SET_ITEM(__pyx_t_1, 46, __pyx_n_s_en_IN);
  __Pyx_INCREF(__pyx_n_s_ar_SA);
  __Pyx_GIVEREF(__pyx_n_s_ar_SA);
  PyList_SET_ITEM(__pyx_t_1, 47, __pyx_n_s_ar_SA);
  __Pyx_INCREF(__pyx_n_s_ka_GE);
  __Pyx_GIVEREF(__pyx_n_s_ka_GE);
  PyList_SET_ITEM(__pyx_t_1, 48, __pyx_n_s_ka_GE);
  __Pyx_INCREF(__pyx_n_s_es_CO);
  __Pyx_GIVEREF(__pyx_n_s_es_CO);
  PyList_SET_ITEM(__pyx_t_1, 49, __pyx_n_s_es_CO);
  __Pyx_INCREF(__pyx_n_s_es_SV);
  __Pyx_GIVEREF(__pyx_n_s_es_SV);
  PyList_SET_ITEM(__pyx_t_1, 50, __pyx_n_s_es_SV);
  __Pyx_INCREF(__pyx_n_s_hr_HR);
  __Pyx_GIVEREF(__pyx_n_s_hr_HR);
  PyList_SET_ITEM(__pyx_t_1, 51, __pyx_n_s_hr_HR);
  __Pyx_INCREF(__pyx_n_s_ar_JO);
  __Pyx_GIVEREF(__pyx_n_s_ar_JO);
  PyList_SET_ITEM(__pyx_t_1, 52, __pyx_n_s_ar_JO);
  __Pyx_INCREF(__pyx_n_s_es_PE);
  __Pyx_GIVEREF(__pyx_n_s_es_PE);
  PyList_SET_ITEM(__pyx_t_1, 53, __pyx_n_s_es_PE);
  __Pyx_INCREF(__pyx_n_s_it_SM);
  __Pyx_GIVEREF(__pyx_n_s_it_SM);
  PyList_SET_ITEM(__pyx_t_1, 54, __pyx_n_s_it_SM);
  __Pyx_INCREF(__pyx_n_s_ar_AR);
  __Pyx_GIVEREF(__pyx_n_s_ar_AR);
  PyList_SET_ITEM(__pyx_t_1, 55, __pyx_n_s_ar_AR);
  __Pyx_INCREF(__pyx_n_s_en_SE);
  __Pyx_GIVEREF(__pyx_n_s_en_SE);
  PyList_SET_ITEM(__pyx_t_1, 56, __pyx_n_s_en_SE);
  __Pyx_INCREF(__pyx_n_s_nb_NO);
  __Pyx_GIVEREF(__pyx_n_s_nb_NO);
  PyList_SET_ITEM(__pyx_t_1, 57, __pyx_n_s_nb_NO);
  __Pyx_INCREF(__pyx_n_s_sk_SK);
  __Pyx_GIVEREF(__pyx_n_s_sk_SK);
  PyList_SET_ITEM(__pyx_t_1, 58, __pyx_n_s_sk_SK);
  __Pyx_INCREF(__pyx_n_s_bs_BA);
  __Pyx_GIVEREF(__pyx_n_s_bs_BA);
  PyList_SET_ITEM(__pyx_t_1, 59, __pyx_n_s_bs_BA);
  __Pyx_INCREF(__pyx_n_s_nl_BE);
  __Pyx_GIVEREF(__pyx_n_s_nl_BE);
  PyList_SET_ITEM(__pyx_t_1, 60, __pyx_n_s_nl_BE);
  __Pyx_INCREF(__pyx_n_s_uz_UZ);
  __Pyx_GIVEREF(__pyx_n_s_uz_UZ);
  PyList_SET_ITEM(__pyx_t_1, 61, __pyx_n_s_uz_UZ);
  __Pyx_INCREF(__pyx_n_s_sl_SI);
  __Pyx_GIVEREF(__pyx_n_s_sl_SI);
  PyList_SET_ITEM(__pyx_t_1, 62, __pyx_n_s_sl_SI);
  __Pyx_INCREF(__pyx_n_s_es_CL);
  __Pyx_GIVEREF(__pyx_n_s_es_CL);
  PyList_SET_ITEM(__pyx_t_1, 63, __pyx_n_s_es_CL);
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_rc);
  __pyx_t_3 = __pyx_cur_scope->__pyx_v_rc; __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_2 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_4, __pyx_t_1) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 78, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_locale = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_kp_s_0_0, __pyx_n_s_format); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__15, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__16, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__17, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = NULL;
  __pyx_t_7 = 0;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
      __pyx_t_7 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[4] = {__pyx_t_6, __pyx_t_1, __pyx_t_4, __pyx_t_5};
    __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_7, 3+__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 79, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[4] = {__pyx_t_6, __pyx_t_1, __pyx_t_4, __pyx_t_5};
    __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_7, 3+__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 79, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  {
    __pyx_t_8 = PyTuple_New(3+__pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 79, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    if (__pyx_t_6) {
      __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_6); __pyx_t_6 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_8, 0+__pyx_t_7, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_8, 1+__pyx_t_7, __pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_8, 2+__pyx_t_7, __pyx_t_5);
    __pyx_t_1 = 0;
    __pyx_t_4 = 0;
    __pyx_t_5 = 0;
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_8, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 79, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_versi = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__19, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_8 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyString_Type)), __pyx_t_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyList_New(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_8);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_2, 2, __pyx_t_5);
  __pyx_t_3 = 0;
  __pyx_t_8 = 0;
  __pyx_t_5 = 0;
  __Pyx_GIVEREF(__pyx_t_2);
  __pyx_cur_scope->__pyx_v_iphone = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;

  
  __pyx_t_5 = PyList_New(9); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 81, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_INCREF(__pyx_n_s_Telkomsel);
  __Pyx_GIVEREF(__pyx_n_s_Telkomsel);
  PyList_SET_ITEM(__pyx_t_5, 0, __pyx_n_s_Telkomsel);
  __Pyx_INCREF(__pyx_n_s_AXIS);
  __Pyx_GIVEREF(__pyx_n_s_AXIS);
  PyList_SET_ITEM(__pyx_t_5, 1, __pyx_n_s_AXIS);
  __Pyx_INCREF(__pyx_n_s_Indosat);
  __Pyx_GIVEREF(__pyx_n_s_Indosat);
  PyList_SET_ITEM(__pyx_t_5, 2, __pyx_n_s_Indosat);
  __Pyx_INCREF(__pyx_n_s_XL);
  __Pyx_GIVEREF(__pyx_n_s_XL);
  PyList_SET_ITEM(__pyx_t_5, 3, __pyx_n_s_XL);
  __Pyx_INCREF(__pyx_kp_s_3SinyalKuatHemat);
  __Pyx_GIVEREF(__pyx_kp_s_3SinyalKuatHemat);
  PyList_SET_ITEM(__pyx_t_5, 4, __pyx_kp_s_3SinyalKuatHemat);
  __Pyx_INCREF(__pyx_kp_s_Tsel_PakaiMasker);
  __Pyx_GIVEREF(__pyx_kp_s_Tsel_PakaiMasker);
  PyList_SET_ITEM(__pyx_t_5, 5, __pyx_kp_s_Tsel_PakaiMasker);
  __Pyx_INCREF(__pyx_kp_s_XL_Axiata);
  __Pyx_GIVEREF(__pyx_kp_s_XL_Axiata);
  PyList_SET_ITEM(__pyx_t_5, 6, __pyx_kp_s_XL_Axiata);
  __Pyx_INCREF(__pyx_kp_s_by_U_PemiluDamai);
  __Pyx_GIVEREF(__pyx_kp_s_by_U_PemiluDamai);
  PyList_SET_ITEM(__pyx_t_5, 7, __pyx_kp_s_by_U_PemiluDamai);
  __Pyx_INCREF(__pyx_kp_s_Tsel_PemiluDamai);
  __Pyx_GIVEREF(__pyx_kp_s_Tsel_PemiluDamai);
  PyList_SET_ITEM(__pyx_t_5, 8, __pyx_kp_s_Tsel_PemiluDamai);
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_rc);
  __pyx_t_8 = __pyx_cur_scope->__pyx_v_rc; __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_8))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_8);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_8, function);
    }
  }
  __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_8, __pyx_t_3, __pyx_t_5) : __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_t_5);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 81, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_v_fbcr = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_kp_s_Dalvik_2_1_0_iPhone_CPU_iPhone_O, __pyx_n_s_format); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_5 = __pyx_pf_4menu_7api_ios_3genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_3 = __Pyx_PyString_Join(__pyx_n_s__21, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__22, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_1 = __pyx_pf_4menu_7api_ios_6genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = __Pyx_PyString_Join(__pyx_kp_s__23, __pyx_t_1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_9 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __pyx_t_10 = NULL;
  __pyx_t_7 = 0;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_8))) {
    __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_8);
    if (likely(__pyx_t_10)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
      __Pyx_INCREF(__pyx_t_10);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_8, function);
      __pyx_t_7 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_8)) {
    PyObject *__pyx_temp[8] = {__pyx_t_10, __pyx_t_3, __pyx_t_5, __pyx_t_4, __pyx_t_6, __pyx_t_1, __pyx_v_locale, __pyx_t_9};
    __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_7, 7+__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 82, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_8)) {
    PyObject *__pyx_temp[8] = {__pyx_t_10, __pyx_t_3, __pyx_t_5, __pyx_t_4, __pyx_t_6, __pyx_t_1, __pyx_v_locale, __pyx_t_9};
    __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_7, 7+__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 82, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  } else
  #endif
  {
    __pyx_t_11 = PyTuple_New(7+__pyx_t_7); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 82, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    if (__pyx_t_10) {
      __Pyx_GIVEREF(__pyx_t_10); PyTuple_SET_ITEM(__pyx_t_11, 0, __pyx_t_10); __pyx_t_10 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_11, 0+__pyx_t_7, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_11, 1+__pyx_t_7, __pyx_t_5);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_11, 2+__pyx_t_7, __pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_6);
    PyTuple_SET_ITEM(__pyx_t_11, 3+__pyx_t_7, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_11, 4+__pyx_t_7, __pyx_t_1);
    __Pyx_INCREF(__pyx_v_locale);
    __Pyx_GIVEREF(__pyx_v_locale);
    PyTuple_SET_ITEM(__pyx_t_11, 5+__pyx_t_7, __pyx_v_locale);
    __Pyx_GIVEREF(__pyx_t_9);
    PyTuple_SET_ITEM(__pyx_t_11, 6+__pyx_t_7, __pyx_t_9);
    __pyx_t_3 = 0;
    __pyx_t_5 = 0;
    __pyx_t_4 = 0;
    __pyx_t_6 = 0;
    __pyx_t_1 = 0;
    __pyx_t_9 = 0;
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_t_11, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 82, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  }
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_v_ios_ = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_kp_s_Dalvik_2_1_0_iPhone_CPU_iPhone_O_2, __pyx_n_s_format); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_11 = __pyx_pf_4menu_7api_ios_9genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __pyx_t_9 = __Pyx_PyString_Join(__pyx_n_s__21, __pyx_t_11); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  __pyx_t_11 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__22, NULL); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = __pyx_pf_4menu_7api_ios_12genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_4 = __Pyx_PyString_Join(__pyx_kp_s__23, __pyx_t_6); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_3 = NULL;
  __pyx_t_7 = 0;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_8))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_8);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_8, function);
      __pyx_t_7 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_8)) {
    PyObject *__pyx_temp[11] = {__pyx_t_3, __pyx_t_9, __pyx_v_versi, __pyx_v_kode, __pyx_t_11, __pyx_t_1, __pyx_t_4, __pyx_t_6, __pyx_v_locale, __pyx_t_5, __pyx_v_kode};
    __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_7, 10+__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 83, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_8)) {
    PyObject *__pyx_temp[11] = {__pyx_t_3, __pyx_t_9, __pyx_v_versi, __pyx_v_kode, __pyx_t_11, __pyx_t_1, __pyx_t_4, __pyx_t_6, __pyx_v_locale, __pyx_t_5, __pyx_v_kode};
    __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_7, 10+__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 83, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  {
    __pyx_t_10 = PyTuple_New(10+__pyx_t_7); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 83, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_10);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_10, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_9);
    PyTuple_SET_ITEM(__pyx_t_10, 0+__pyx_t_7, __pyx_t_9);
    __Pyx_INCREF(__pyx_v_versi);
    __Pyx_GIVEREF(__pyx_v_versi);
    PyTuple_SET_ITEM(__pyx_t_10, 1+__pyx_t_7, __pyx_v_versi);
    __Pyx_INCREF(__pyx_v_kode);
    __Pyx_GIVEREF(__pyx_v_kode);
    PyTuple_SET_ITEM(__pyx_t_10, 2+__pyx_t_7, __pyx_v_kode);
    __Pyx_GIVEREF(__pyx_t_11);
    PyTuple_SET_ITEM(__pyx_t_10, 3+__pyx_t_7, __pyx_t_11);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_10, 4+__pyx_t_7, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_10, 5+__pyx_t_7, __pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_6);
    PyTuple_SET_ITEM(__pyx_t_10, 6+__pyx_t_7, __pyx_t_6);
    __Pyx_INCREF(__pyx_v_locale);
    __Pyx_GIVEREF(__pyx_v_locale);
    PyTuple_SET_ITEM(__pyx_t_10, 7+__pyx_t_7, __pyx_v_locale);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_10, 8+__pyx_t_7, __pyx_t_5);
    __Pyx_INCREF(__pyx_v_kode);
    __Pyx_GIVEREF(__pyx_v_kode);
    PyTuple_SET_ITEM(__pyx_t_10, 9+__pyx_t_7, __pyx_v_kode);
    __pyx_t_9 = 0;
    __pyx_t_11 = 0;
    __pyx_t_1 = 0;
    __pyx_t_4 = 0;
    __pyx_t_6 = 0;
    __pyx_t_5 = 0;
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_t_10, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 83, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  }
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_v_for_ios = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_kp_s_Dalvik_2_1_0_iPhone_CPU_iPhone_O_3, __pyx_n_s_format); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_10 = __pyx_pf_4menu_7api_ios_15genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_5 = __Pyx_PyString_Join(__pyx_n_s__21, __pyx_t_10); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  __pyx_t_10 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__22, NULL); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_6 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_4 = __pyx_pf_4menu_7api_ios_18genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_1 = __Pyx_PyString_Join(__pyx_kp_s__23, __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_11 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __pyx_t_9 = NULL;
  __pyx_t_7 = 0;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_8))) {
    __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_8);
    if (likely(__pyx_t_9)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
      __Pyx_INCREF(__pyx_t_9);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_8, function);
      __pyx_t_7 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_8)) {
    PyObject *__pyx_temp[12] = {__pyx_t_9, __pyx_t_5, __pyx_v_versi, __pyx_v_kode, __pyx_t_10, __pyx_t_6, __pyx_t_1, __pyx_t_4, __pyx_v_fbcr, __pyx_v_locale, __pyx_t_11, __pyx_v_kode};
    __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_7, 11+__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 84, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_8)) {
    PyObject *__pyx_temp[12] = {__pyx_t_9, __pyx_t_5, __pyx_v_versi, __pyx_v_kode, __pyx_t_10, __pyx_t_6, __pyx_t_1, __pyx_t_4, __pyx_v_fbcr, __pyx_v_locale, __pyx_t_11, __pyx_v_kode};
    __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_7, 11+__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 84, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  } else
  #endif
  {
    __pyx_t_3 = PyTuple_New(11+__pyx_t_7); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 84, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (__pyx_t_9) {
      __Pyx_GIVEREF(__pyx_t_9); PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_9); __pyx_t_9 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_3, 0+__pyx_t_7, __pyx_t_5);
    __Pyx_INCREF(__pyx_v_versi);
    __Pyx_GIVEREF(__pyx_v_versi);
    PyTuple_SET_ITEM(__pyx_t_3, 1+__pyx_t_7, __pyx_v_versi);
    __Pyx_INCREF(__pyx_v_kode);
    __Pyx_GIVEREF(__pyx_v_kode);
    PyTuple_SET_ITEM(__pyx_t_3, 2+__pyx_t_7, __pyx_v_kode);
    __Pyx_GIVEREF(__pyx_t_10);
    PyTuple_SET_ITEM(__pyx_t_3, 3+__pyx_t_7, __pyx_t_10);
    __Pyx_GIVEREF(__pyx_t_6);
    PyTuple_SET_ITEM(__pyx_t_3, 4+__pyx_t_7, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_3, 5+__pyx_t_7, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_3, 6+__pyx_t_7, __pyx_t_4);
    __Pyx_INCREF(__pyx_v_fbcr);
    __Pyx_GIVEREF(__pyx_v_fbcr);
    PyTuple_SET_ITEM(__pyx_t_3, 7+__pyx_t_7, __pyx_v_fbcr);
    __Pyx_INCREF(__pyx_v_locale);
    __Pyx_GIVEREF(__pyx_v_locale);
    PyTuple_SET_ITEM(__pyx_t_3, 8+__pyx_t_7, __pyx_v_locale);
    __Pyx_GIVEREF(__pyx_t_11);
    PyTuple_SET_ITEM(__pyx_t_3, 9+__pyx_t_7, __pyx_t_11);
    __Pyx_INCREF(__pyx_v_kode);
    __Pyx_GIVEREF(__pyx_v_kode);
    PyTuple_SET_ITEM(__pyx_t_3, 10+__pyx_t_7, __pyx_v_kode);
    __pyx_t_5 = 0;
    __pyx_t_10 = 0;
    __pyx_t_6 = 0;
    __pyx_t_1 = 0;
    __pyx_t_4 = 0;
    __pyx_t_11 = 0;
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_t_3, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 84, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  }
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_v_mes_ios = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_kp_s_Dalvik_2_1_0_iPhone_CPU_iPhone_O_4, __pyx_n_s_format); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_3 = __pyx_pf_4menu_7api_ios_21genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_11 = __Pyx_PyString_Join(__pyx_n_s__21, __pyx_t_3); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_11);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__22, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_1 = __pyx_pf_4menu_7api_ios_24genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = __Pyx_PyString_Join(__pyx_kp_s__23, __pyx_t_1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_10 = __Pyx_PyObject_Call(__pyx_v_rr, __pyx_tuple__24, NULL); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __pyx_t_5 = NULL;
  __pyx_t_7 = 0;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_8))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_8);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_8, function);
      __pyx_t_7 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_8)) {
    PyObject *__pyx_temp[9] = {__pyx_t_5, __pyx_t_11, __pyx_v_versi, __pyx_v_kode, __pyx_t_3, __pyx_t_4, __pyx_t_6, __pyx_t_1, __pyx_t_10};
    __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_7, 8+__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 85, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_8)) {
    PyObject *__pyx_temp[9] = {__pyx_t_5, __pyx_t_11, __pyx_v_versi, __pyx_v_kode, __pyx_t_3, __pyx_t_4, __pyx_t_6, __pyx_t_1, __pyx_t_10};
    __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_7, 8+__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 85, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
  } else
  #endif
  {
    __pyx_t_9 = PyTuple_New(8+__pyx_t_7); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 85, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (__pyx_t_5) {
      __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_5); __pyx_t_5 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_11);
    PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_7, __pyx_t_11);
    __Pyx_INCREF(__pyx_v_versi);
    __Pyx_GIVEREF(__pyx_v_versi);
    PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_7, __pyx_v_versi);
    __Pyx_INCREF(__pyx_v_kode);
    __Pyx_GIVEREF(__pyx_v_kode);
    PyTuple_SET_ITEM(__pyx_t_9, 2+__pyx_t_7, __pyx_v_kode);
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_9, 3+__pyx_t_7, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_9, 4+__pyx_t_7, __pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_6);
    PyTuple_SET_ITEM(__pyx_t_9, 5+__pyx_t_7, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_9, 6+__pyx_t_7, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_10);
    PyTuple_SET_ITEM(__pyx_t_9, 7+__pyx_t_7, __pyx_t_10);
    __pyx_t_11 = 0;
    __pyx_t_3 = 0;
    __pyx_t_4 = 0;
    __pyx_t_6 = 0;
    __pyx_t_1 = 0;
    __pyx_t_10 = 0;
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_t_9, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 85, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  }
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_v_mes_lite_ios = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_8 = PyList_New(4); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 86, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_INCREF(__pyx_v_mes_lite_ios);
  __Pyx_GIVEREF(__pyx_v_mes_lite_ios);
  PyList_SET_ITEM(__pyx_t_8, 0, __pyx_v_mes_lite_ios);
  __Pyx_INCREF(__pyx_v_mes_ios);
  __Pyx_GIVEREF(__pyx_v_mes_ios);
  PyList_SET_ITEM(__pyx_t_8, 1, __pyx_v_mes_ios);
  __Pyx_INCREF(__pyx_v_for_ios);
  __Pyx_GIVEREF(__pyx_v_for_ios);
  PyList_SET_ITEM(__pyx_t_8, 2, __pyx_v_for_ios);
  __Pyx_INCREF(__pyx_v_ios_);
  __Pyx_GIVEREF(__pyx_v_ios_);
  PyList_SET_ITEM(__pyx_t_8, 3, __pyx_v_ios_);
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_rc);
  __pyx_t_9 = __pyx_cur_scope->__pyx_v_rc; __pyx_t_10 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_9))) {
    __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_9);
    if (likely(__pyx_t_10)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
      __Pyx_INCREF(__pyx_t_10);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_9, function);
    }
  }
  __pyx_t_2 = (__pyx_t_10) ? __Pyx_PyObject_Call2Args(__pyx_t_9, __pyx_t_10, __pyx_t_8) : __Pyx_PyObject_CallOneArg(__pyx_t_9, __pyx_t_8);
  __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 86, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_AddTraceback("menu.api_ios", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_rr);
  __Pyx_XDECREF(__pyx_v_kode);
  __Pyx_XDECREF(__pyx_v_locale);
  __Pyx_XDECREF(__pyx_v_versi);
  __Pyx_XDECREF(__pyx_v_fbcr);
  __Pyx_XDECREF(__pyx_v_ios_);
  __Pyx_XDECREF(__pyx_v_for_ios);
  __Pyx_XDECREF(__pyx_v_mes_ios);
  __Pyx_XDECREF(__pyx_v_mes_lite_ios);
  __Pyx_XDECREF(__pyx_gb_4menu_7api_ios_2generator1);
  __Pyx_XDECREF(__pyx_gb_4menu_7api_ios_5generator2);
  __Pyx_XDECREF(__pyx_gb_4menu_7api_ios_8generator3);
  __Pyx_XDECREF(__pyx_gb_4menu_7api_ios_11generator4);
  __Pyx_XDECREF(__pyx_gb_4menu_7api_ios_14generator5);
  __Pyx_XDECREF(__pyx_gb_4menu_7api_ios_17generator6);
  __Pyx_XDECREF(__pyx_gb_4menu_7api_ios_20generator7);
  __Pyx_XDECREF(__pyx_gb_4menu_7api_ios_23generator8);
  __Pyx_XDECREF(__pyx_gb_4menu_7api_ios_26generator9);
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_4menu_11ua_web(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); 
static PyMethodDef __pyx_mdef_4menu_11ua_web = {"ua_web", (PyCFunction)__pyx_pw_4menu_11ua_web, METH_NOARGS, 0};
static PyObject *__pyx_pw_4menu_11ua_web(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("ua_web (wrapper)", 0);
  __pyx_r = __pyx_pf_4menu_10ua_web(__pyx_self);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_4menu_10ua_web(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  Py_UCS4 __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("ua_web", 0);

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_rc); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyTuple_New(3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = 0;
  __pyx_t_5 = 127;
  __Pyx_INCREF(__pyx_kp_u_Mozilla_5_0_Linux_Android_10_K_A);
  __pyx_t_4 += 81;
  __Pyx_GIVEREF(__pyx_kp_u_Mozilla_5_0_Linux_Android_10_K_A);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u_Mozilla_5_0_Linux_Android_10_K_A);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_versi_chrome); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_7 = __Pyx_PyObject_FormatSimple(__pyx_t_6, __pyx_empty_unicode); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_7) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_7);
  __pyx_t_7 = 0;
  __Pyx_INCREF(__pyx_kp_u_Mobile_Safari_537_36);
  __pyx_t_4 += 21;
  __Pyx_GIVEREF(__pyx_kp_u_Mobile_Safari_537_36);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u_Mobile_Safari_537_36);
  __pyx_t_7 = __Pyx_PyUnicode_Join(__pyx_t_3, 3, __pyx_t_4, __pyx_t_5); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = 0;
  __pyx_t_5 = 127;
  __Pyx_INCREF(__pyx_kp_u_Mozilla_5_0_Windows_NT_10_0_Win6);
  __pyx_t_4 += 88;
  __Pyx_GIVEREF(__pyx_kp_u_Mozilla_5_0_Windows_NT_10_0_Win6);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u_Mozilla_5_0_Windows_NT_10_0_Win6);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_versi_chrome); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_8 = __Pyx_PyObject_FormatSimple(__pyx_t_6, __pyx_empty_unicode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_8) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_8);
  __pyx_t_8 = 0;
  __Pyx_INCREF(__pyx_kp_u_Mobile_Safari_537_36);
  __pyx_t_4 += 21;
  __Pyx_GIVEREF(__pyx_kp_u_Mobile_Safari_537_36);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u_Mobile_Safari_537_36);
  __pyx_t_8 = __Pyx_PyUnicode_Join(__pyx_t_3, 3, __pyx_t_4, __pyx_t_5); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(9); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = 0;
  __pyx_t_5 = 127;
  __Pyx_INCREF(__pyx_kp_u_Mozilla_5_0_Macintosh_Intel_Mac);
  __pyx_t_4 += 39;
  __Pyx_GIVEREF(__pyx_kp_u_Mozilla_5_0_Macintosh_Intel_Mac);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u_Mozilla_5_0_Macintosh_Intel_Mac);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_rr); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_tuple__25, NULL); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_PyObject_FormatSimple(__pyx_t_9, __pyx_empty_unicode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_INCREF(__pyx_n_u__21);
  __pyx_t_4 += 1;
  __Pyx_GIVEREF(__pyx_n_u__21);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_n_u__21);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_rr); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_PyObject_FormatSimple(__pyx_t_9, __pyx_empty_unicode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_3, 3, __pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_INCREF(__pyx_n_u__21);
  __pyx_t_4 += 1;
  __Pyx_GIVEREF(__pyx_n_u__21);
  PyTuple_SET_ITEM(__pyx_t_3, 4, __pyx_n_u__21);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_rr); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = __Pyx_PyObject_FormatSimple(__pyx_t_9, __pyx_empty_unicode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_6) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_3, 5, __pyx_t_6);
  __pyx_t_6 = 0;
  __Pyx_INCREF(__pyx_kp_u_AppleWebKit_540_77_KHTML_like_G);
  __pyx_t_4 += 47;
  __Pyx_GIVEREF(__pyx_kp_u_AppleWebKit_540_77_KHTML_like_G);
  PyTuple_SET_ITEM(__pyx_t_3, 6, __pyx_kp_u_AppleWebKit_540_77_KHTML_like_G);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_versi_chrome); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_9 = __Pyx_PyObject_FormatSimple(__pyx_t_6, __pyx_empty_unicode); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_9) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_9) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_9);
  __Pyx_GIVEREF(__pyx_t_9);
  PyTuple_SET_ITEM(__pyx_t_3, 7, __pyx_t_9);
  __pyx_t_9 = 0;
  __Pyx_INCREF(__pyx_kp_u_Safari_232_65);
  __pyx_t_4 += 14;
  __Pyx_GIVEREF(__pyx_kp_u_Safari_232_65);
  PyTuple_SET_ITEM(__pyx_t_3, 8, __pyx_kp_u_Safari_232_65);
  __pyx_t_9 = __Pyx_PyUnicode_Join(__pyx_t_3, 9, __pyx_t_4, __pyx_t_5); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = 0;
  __pyx_t_5 = 127;
  __Pyx_INCREF(__pyx_kp_u_Mozilla_5_0_X11_Linux_x86_64_App);
  __pyx_t_4 += 78;
  __Pyx_GIVEREF(__pyx_kp_u_Mozilla_5_0_X11_Linux_x86_64_App);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u_Mozilla_5_0_X11_Linux_x86_64_App);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_versi_chrome); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_10 = __Pyx_PyObject_FormatSimple(__pyx_t_6, __pyx_empty_unicode); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_5 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_10) > __pyx_t_5) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_10) : __pyx_t_5;
  __pyx_t_4 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_10);
  __Pyx_GIVEREF(__pyx_t_10);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_10);
  __pyx_t_10 = 0;
  __Pyx_INCREF(__pyx_kp_u_Safari_537_36);
  __pyx_t_4 += 14;
  __Pyx_GIVEREF(__pyx_kp_u_Safari_537_36);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u_Safari_537_36);
  __pyx_t_10 = __Pyx_PyUnicode_Join(__pyx_t_3, 3, __pyx_t_4, __pyx_t_5); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_10);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyList_New(4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_7);
  PyList_SET_ITEM(__pyx_t_3, 0, __pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_8);
  PyList_SET_ITEM(__pyx_t_3, 1, __pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_9);
  PyList_SET_ITEM(__pyx_t_3, 2, __pyx_t_9);
  __Pyx_GIVEREF(__pyx_t_10);
  PyList_SET_ITEM(__pyx_t_3, 3, __pyx_t_10);
  __pyx_t_7 = 0;
  __pyx_t_8 = 0;
  __pyx_t_9 = 0;
  __pyx_t_10 = 0;
  __pyx_t_10 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_10)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_10);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_10) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_10, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_AddTraceback("menu.ua_web", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static struct __pyx_obj_4menu___pyx_scope_struct__ua_api *__pyx_freelist_4menu___pyx_scope_struct__ua_api[8];
static int __pyx_freecount_4menu___pyx_scope_struct__ua_api = 0;

static PyObject *__pyx_tp_new_4menu___pyx_scope_struct__ua_api(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4menu___pyx_scope_struct__ua_api > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct__ua_api)))) {
    o = (PyObject*)__pyx_freelist_4menu___pyx_scope_struct__ua_api[--__pyx_freecount_4menu___pyx_scope_struct__ua_api];
    memset(o, 0, sizeof(struct __pyx_obj_4menu___pyx_scope_struct__ua_api));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4menu___pyx_scope_struct__ua_api(PyObject *o) {
  struct __pyx_obj_4menu___pyx_scope_struct__ua_api *p = (struct __pyx_obj_4menu___pyx_scope_struct__ua_api *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_rc);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4menu___pyx_scope_struct__ua_api < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct__ua_api)))) {
    __pyx_freelist_4menu___pyx_scope_struct__ua_api[__pyx_freecount_4menu___pyx_scope_struct__ua_api++] = ((struct __pyx_obj_4menu___pyx_scope_struct__ua_api *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4menu___pyx_scope_struct__ua_api(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4menu___pyx_scope_struct__ua_api *p = (struct __pyx_obj_4menu___pyx_scope_struct__ua_api *)o;
  if (p->__pyx_v_rc) {
    e = (*v)(p->__pyx_v_rc, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_4menu___pyx_scope_struct__ua_api(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_4menu___pyx_scope_struct__ua_api *p = (struct __pyx_obj_4menu___pyx_scope_struct__ua_api *)o;
  tmp = ((PyObject*)p->__pyx_v_rc);
  p->__pyx_v_rc = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyTypeObject __pyx_type_4menu___pyx_scope_struct__ua_api = {
  PyVarObject_HEAD_INIT(0, 0)
  "menu.__pyx_scope_struct__ua_api", 
  sizeof(struct __pyx_obj_4menu___pyx_scope_struct__ua_api), 
  0, 
  __pyx_tp_dealloc_4menu___pyx_scope_struct__ua_api, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4menu___pyx_scope_struct__ua_api, 
  __pyx_tp_clear_4menu___pyx_scope_struct__ua_api, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4menu___pyx_scope_struct__ua_api, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr *__pyx_freelist_4menu___pyx_scope_struct_1_genexpr[8];
static int __pyx_freecount_4menu___pyx_scope_struct_1_genexpr = 0;

static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_1_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4menu___pyx_scope_struct_1_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr)))) {
    o = (PyObject*)__pyx_freelist_4menu___pyx_scope_struct_1_genexpr[--__pyx_freecount_4menu___pyx_scope_struct_1_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4menu___pyx_scope_struct_1_genexpr(PyObject *o) {
  struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4menu___pyx_scope_struct_1_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr)))) {
    __pyx_freelist_4menu___pyx_scope_struct_1_genexpr[__pyx_freecount_4menu___pyx_scope_struct_1_genexpr++] = ((struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4menu___pyx_scope_struct_1_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_4menu___pyx_scope_struct_1_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "menu.__pyx_scope_struct_1_genexpr", 
  sizeof(struct __pyx_obj_4menu___pyx_scope_struct_1_genexpr), 
  0, 
  __pyx_tp_dealloc_4menu___pyx_scope_struct_1_genexpr, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4menu___pyx_scope_struct_1_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4menu___pyx_scope_struct_1_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *__pyx_freelist_4menu___pyx_scope_struct_2_api_ios[8];
static int __pyx_freecount_4menu___pyx_scope_struct_2_api_ios = 0;

static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_2_api_ios(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4menu___pyx_scope_struct_2_api_ios > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios)))) {
    o = (PyObject*)__pyx_freelist_4menu___pyx_scope_struct_2_api_ios[--__pyx_freecount_4menu___pyx_scope_struct_2_api_ios];
    memset(o, 0, sizeof(struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4menu___pyx_scope_struct_2_api_ios(PyObject *o) {
  struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *p = (struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_iphone);
  Py_CLEAR(p->__pyx_v_rc);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4menu___pyx_scope_struct_2_api_ios < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios)))) {
    __pyx_freelist_4menu___pyx_scope_struct_2_api_ios[__pyx_freecount_4menu___pyx_scope_struct_2_api_ios++] = ((struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4menu___pyx_scope_struct_2_api_ios(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *p = (struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *)o;
  if (p->__pyx_v_iphone) {
    e = (*v)(p->__pyx_v_iphone, a); if (e) return e;
  }
  if (p->__pyx_v_rc) {
    e = (*v)(p->__pyx_v_rc, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_4menu___pyx_scope_struct_2_api_ios(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *p = (struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios *)o;
  tmp = ((PyObject*)p->__pyx_v_iphone);
  p->__pyx_v_iphone = ((PyObject*)Py_None); Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_rc);
  p->__pyx_v_rc = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyTypeObject __pyx_type_4menu___pyx_scope_struct_2_api_ios = {
  PyVarObject_HEAD_INIT(0, 0)
  "menu.__pyx_scope_struct_2_api_ios", 
  sizeof(struct __pyx_obj_4menu___pyx_scope_struct_2_api_ios), 
  0, 
  __pyx_tp_dealloc_4menu___pyx_scope_struct_2_api_ios, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4menu___pyx_scope_struct_2_api_ios, 
  __pyx_tp_clear_4menu___pyx_scope_struct_2_api_ios, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4menu___pyx_scope_struct_2_api_ios, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr *__pyx_freelist_4menu___pyx_scope_struct_3_genexpr[8];
static int __pyx_freecount_4menu___pyx_scope_struct_3_genexpr = 0;

static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_3_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4menu___pyx_scope_struct_3_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr)))) {
    o = (PyObject*)__pyx_freelist_4menu___pyx_scope_struct_3_genexpr[--__pyx_freecount_4menu___pyx_scope_struct_3_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4menu___pyx_scope_struct_3_genexpr(PyObject *o) {
  struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4menu___pyx_scope_struct_3_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr)))) {
    __pyx_freelist_4menu___pyx_scope_struct_3_genexpr[__pyx_freecount_4menu___pyx_scope_struct_3_genexpr++] = ((struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4menu___pyx_scope_struct_3_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_4menu___pyx_scope_struct_3_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "menu.__pyx_scope_struct_3_genexpr", 
  sizeof(struct __pyx_obj_4menu___pyx_scope_struct_3_genexpr), 
  0, 
  __pyx_tp_dealloc_4menu___pyx_scope_struct_3_genexpr, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4menu___pyx_scope_struct_3_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4menu___pyx_scope_struct_3_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr *__pyx_freelist_4menu___pyx_scope_struct_4_genexpr[8];
static int __pyx_freecount_4menu___pyx_scope_struct_4_genexpr = 0;

static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_4_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4menu___pyx_scope_struct_4_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr)))) {
    o = (PyObject*)__pyx_freelist_4menu___pyx_scope_struct_4_genexpr[--__pyx_freecount_4menu___pyx_scope_struct_4_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4menu___pyx_scope_struct_4_genexpr(PyObject *o) {
  struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_x);
  Py_CLEAR(p->__pyx_t_0);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4menu___pyx_scope_struct_4_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr)))) {
    __pyx_freelist_4menu___pyx_scope_struct_4_genexpr[__pyx_freecount_4menu___pyx_scope_struct_4_genexpr++] = ((struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4menu___pyx_scope_struct_4_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_x) {
    e = (*v)(p->__pyx_v_x, a); if (e) return e;
  }
  if (p->__pyx_t_0) {
    e = (*v)(p->__pyx_t_0, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_4menu___pyx_scope_struct_4_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "menu.__pyx_scope_struct_4_genexpr", 
  sizeof(struct __pyx_obj_4menu___pyx_scope_struct_4_genexpr), 
  0, 
  __pyx_tp_dealloc_4menu___pyx_scope_struct_4_genexpr, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4menu___pyx_scope_struct_4_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4menu___pyx_scope_struct_4_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr *__pyx_freelist_4menu___pyx_scope_struct_5_genexpr[8];
static int __pyx_freecount_4menu___pyx_scope_struct_5_genexpr = 0;

static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_5_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4menu___pyx_scope_struct_5_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr)))) {
    o = (PyObject*)__pyx_freelist_4menu___pyx_scope_struct_5_genexpr[--__pyx_freecount_4menu___pyx_scope_struct_5_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4menu___pyx_scope_struct_5_genexpr(PyObject *o) {
  struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_x);
  Py_CLEAR(p->__pyx_t_0);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4menu___pyx_scope_struct_5_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr)))) {
    __pyx_freelist_4menu___pyx_scope_struct_5_genexpr[__pyx_freecount_4menu___pyx_scope_struct_5_genexpr++] = ((struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4menu___pyx_scope_struct_5_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_x) {
    e = (*v)(p->__pyx_v_x, a); if (e) return e;
  }
  if (p->__pyx_t_0) {
    e = (*v)(p->__pyx_t_0, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_4menu___pyx_scope_struct_5_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "menu.__pyx_scope_struct_5_genexpr", 
  sizeof(struct __pyx_obj_4menu___pyx_scope_struct_5_genexpr), 
  0, 
  __pyx_tp_dealloc_4menu___pyx_scope_struct_5_genexpr, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4menu___pyx_scope_struct_5_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4menu___pyx_scope_struct_5_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr *__pyx_freelist_4menu___pyx_scope_struct_6_genexpr[8];
static int __pyx_freecount_4menu___pyx_scope_struct_6_genexpr = 0;

static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_6_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4menu___pyx_scope_struct_6_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr)))) {
    o = (PyObject*)__pyx_freelist_4menu___pyx_scope_struct_6_genexpr[--__pyx_freecount_4menu___pyx_scope_struct_6_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4menu___pyx_scope_struct_6_genexpr(PyObject *o) {
  struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_x);
  Py_CLEAR(p->__pyx_t_0);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4menu___pyx_scope_struct_6_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr)))) {
    __pyx_freelist_4menu___pyx_scope_struct_6_genexpr[__pyx_freecount_4menu___pyx_scope_struct_6_genexpr++] = ((struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4menu___pyx_scope_struct_6_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_x) {
    e = (*v)(p->__pyx_v_x, a); if (e) return e;
  }
  if (p->__pyx_t_0) {
    e = (*v)(p->__pyx_t_0, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_4menu___pyx_scope_struct_6_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "menu.__pyx_scope_struct_6_genexpr", 
  sizeof(struct __pyx_obj_4menu___pyx_scope_struct_6_genexpr), 
  0, 
  __pyx_tp_dealloc_4menu___pyx_scope_struct_6_genexpr, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4menu___pyx_scope_struct_6_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4menu___pyx_scope_struct_6_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr *__pyx_freelist_4menu___pyx_scope_struct_7_genexpr[8];
static int __pyx_freecount_4menu___pyx_scope_struct_7_genexpr = 0;

static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_7_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4menu___pyx_scope_struct_7_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr)))) {
    o = (PyObject*)__pyx_freelist_4menu___pyx_scope_struct_7_genexpr[--__pyx_freecount_4menu___pyx_scope_struct_7_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4menu___pyx_scope_struct_7_genexpr(PyObject *o) {
  struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_x);
  Py_CLEAR(p->__pyx_t_0);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4menu___pyx_scope_struct_7_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr)))) {
    __pyx_freelist_4menu___pyx_scope_struct_7_genexpr[__pyx_freecount_4menu___pyx_scope_struct_7_genexpr++] = ((struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4menu___pyx_scope_struct_7_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_x) {
    e = (*v)(p->__pyx_v_x, a); if (e) return e;
  }
  if (p->__pyx_t_0) {
    e = (*v)(p->__pyx_t_0, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_4menu___pyx_scope_struct_7_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "menu.__pyx_scope_struct_7_genexpr", 
  sizeof(struct __pyx_obj_4menu___pyx_scope_struct_7_genexpr), 
  0, 
  __pyx_tp_dealloc_4menu___pyx_scope_struct_7_genexpr, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4menu___pyx_scope_struct_7_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4menu___pyx_scope_struct_7_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr *__pyx_freelist_4menu___pyx_scope_struct_8_genexpr[8];
static int __pyx_freecount_4menu___pyx_scope_struct_8_genexpr = 0;

static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_8_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4menu___pyx_scope_struct_8_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr)))) {
    o = (PyObject*)__pyx_freelist_4menu___pyx_scope_struct_8_genexpr[--__pyx_freecount_4menu___pyx_scope_struct_8_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4menu___pyx_scope_struct_8_genexpr(PyObject *o) {
  struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_x);
  Py_CLEAR(p->__pyx_t_0);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4menu___pyx_scope_struct_8_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr)))) {
    __pyx_freelist_4menu___pyx_scope_struct_8_genexpr[__pyx_freecount_4menu___pyx_scope_struct_8_genexpr++] = ((struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4menu___pyx_scope_struct_8_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_x) {
    e = (*v)(p->__pyx_v_x, a); if (e) return e;
  }
  if (p->__pyx_t_0) {
    e = (*v)(p->__pyx_t_0, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_4menu___pyx_scope_struct_8_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "menu.__pyx_scope_struct_8_genexpr", 
  sizeof(struct __pyx_obj_4menu___pyx_scope_struct_8_genexpr), 
  0, 
  __pyx_tp_dealloc_4menu___pyx_scope_struct_8_genexpr, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4menu___pyx_scope_struct_8_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4menu___pyx_scope_struct_8_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr *__pyx_freelist_4menu___pyx_scope_struct_9_genexpr[8];
static int __pyx_freecount_4menu___pyx_scope_struct_9_genexpr = 0;

static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_9_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4menu___pyx_scope_struct_9_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr)))) {
    o = (PyObject*)__pyx_freelist_4menu___pyx_scope_struct_9_genexpr[--__pyx_freecount_4menu___pyx_scope_struct_9_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4menu___pyx_scope_struct_9_genexpr(PyObject *o) {
  struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_x);
  Py_CLEAR(p->__pyx_t_0);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4menu___pyx_scope_struct_9_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr)))) {
    __pyx_freelist_4menu___pyx_scope_struct_9_genexpr[__pyx_freecount_4menu___pyx_scope_struct_9_genexpr++] = ((struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4menu___pyx_scope_struct_9_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_x) {
    e = (*v)(p->__pyx_v_x, a); if (e) return e;
  }
  if (p->__pyx_t_0) {
    e = (*v)(p->__pyx_t_0, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_4menu___pyx_scope_struct_9_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "menu.__pyx_scope_struct_9_genexpr", 
  sizeof(struct __pyx_obj_4menu___pyx_scope_struct_9_genexpr), 
  0, 
  __pyx_tp_dealloc_4menu___pyx_scope_struct_9_genexpr, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4menu___pyx_scope_struct_9_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4menu___pyx_scope_struct_9_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr *__pyx_freelist_4menu___pyx_scope_struct_10_genexpr[8];
static int __pyx_freecount_4menu___pyx_scope_struct_10_genexpr = 0;

static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_10_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4menu___pyx_scope_struct_10_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr)))) {
    o = (PyObject*)__pyx_freelist_4menu___pyx_scope_struct_10_genexpr[--__pyx_freecount_4menu___pyx_scope_struct_10_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4menu___pyx_scope_struct_10_genexpr(PyObject *o) {
  struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_x);
  Py_CLEAR(p->__pyx_t_0);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4menu___pyx_scope_struct_10_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr)))) {
    __pyx_freelist_4menu___pyx_scope_struct_10_genexpr[__pyx_freecount_4menu___pyx_scope_struct_10_genexpr++] = ((struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4menu___pyx_scope_struct_10_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_x) {
    e = (*v)(p->__pyx_v_x, a); if (e) return e;
  }
  if (p->__pyx_t_0) {
    e = (*v)(p->__pyx_t_0, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_4menu___pyx_scope_struct_10_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "menu.__pyx_scope_struct_10_genexpr", 
  sizeof(struct __pyx_obj_4menu___pyx_scope_struct_10_genexpr), 
  0, 
  __pyx_tp_dealloc_4menu___pyx_scope_struct_10_genexpr, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4menu___pyx_scope_struct_10_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4menu___pyx_scope_struct_10_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr *__pyx_freelist_4menu___pyx_scope_struct_11_genexpr[8];
static int __pyx_freecount_4menu___pyx_scope_struct_11_genexpr = 0;

static PyObject *__pyx_tp_new_4menu___pyx_scope_struct_11_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_4menu___pyx_scope_struct_11_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr)))) {
    o = (PyObject*)__pyx_freelist_4menu___pyx_scope_struct_11_genexpr[--__pyx_freecount_4menu___pyx_scope_struct_11_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_4menu___pyx_scope_struct_11_genexpr(PyObject *o) {
  struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_x);
  Py_CLEAR(p->__pyx_t_0);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_4menu___pyx_scope_struct_11_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr)))) {
    __pyx_freelist_4menu___pyx_scope_struct_11_genexpr[__pyx_freecount_4menu___pyx_scope_struct_11_genexpr++] = ((struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_4menu___pyx_scope_struct_11_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr *p = (struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_x) {
    e = (*v)(p->__pyx_v_x, a); if (e) return e;
  }
  if (p->__pyx_t_0) {
    e = (*v)(p->__pyx_t_0, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_4menu___pyx_scope_struct_11_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "menu.__pyx_scope_struct_11_genexpr", 
  sizeof(struct __pyx_obj_4menu___pyx_scope_struct_11_genexpr), 
  0, 
  __pyx_tp_dealloc_4menu___pyx_scope_struct_11_genexpr, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_4menu___pyx_scope_struct_11_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_4menu___pyx_scope_struct_11_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
  #if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
  0, 
  #endif
};

static PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

#if PY_MAJOR_VERSION >= 3
#if CYTHON_PEP489_MULTI_PHASE_INIT
static PyObject* __pyx_pymod_create(PyObject *spec, PyModuleDef *def); 
static int __pyx_pymod_exec_menu(PyObject* module); 
static PyModuleDef_Slot __pyx_moduledef_slots[] = {
  {Py_mod_create, (void*)__pyx_pymod_create},
  {Py_mod_exec, (void*)__pyx_pymod_exec_menu},
  {0, NULL}
};
#endif

static struct PyModuleDef __pyx_moduledef = {
    PyModuleDef_HEAD_INIT,
    "menu",
    0, 
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    0, 
  #else
    -1, 
  #endif
    __pyx_methods ,
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    __pyx_moduledef_slots, 
  #else
    NULL, 
  #endif
    NULL, 
    NULL, 
    NULL 
};
#endif
#ifndef CYTHON_SMALL_CODE
#if defined(__clang__)
    #define CYTHON_SMALL_CODE
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
    #define CYTHON_SMALL_CODE __attribute__((cold))
#else
    #define CYTHON_SMALL_CODE
#endif
#endif

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_kp_s_01_Oktober_2021, __pyx_k_01_Oktober_2021, sizeof(__pyx_k_01_Oktober_2021), 0, 0, 1, 0},
  {&__pyx_kp_s_0_0, __pyx_k_0_0, sizeof(__pyx_k_0_0), 0, 0, 1, 0},
  {&__pyx_kp_s_122_0_0_0, __pyx_k_122_0_0_0, sizeof(__pyx_k_122_0_0_0), 0, 0, 1, 0},
  {&__pyx_kp_s_1234567890, __pyx_k_1234567890, sizeof(__pyx_k_1234567890), 0, 0, 1, 0},
  {&__pyx_kp_s_1_91m, __pyx_k_1_91m, sizeof(__pyx_k_1_91m), 0, 0, 1, 0},
  {&__pyx_kp_s_1_92m, __pyx_k_1_92m, sizeof(__pyx_k_1_92m), 0, 0, 1, 0},
  {&__pyx_kp_s_1_93m, __pyx_k_1_93m, sizeof(__pyx_k_1_93m), 0, 0, 1, 0},
  {&__pyx_kp_s_1_97m, __pyx_k_1_97m, sizeof(__pyx_k_1_97m), 0, 0, 1, 0},
  {&__pyx_kp_s_3G, __pyx_k_3G, sizeof(__pyx_k_3G), 0, 0, 1, 0},
  {&__pyx_kp_s_3SinyalKuatHemat, __pyx_k_3SinyalKuatHemat, sizeof(__pyx_k_3SinyalKuatHemat), 0, 0, 1, 0},
  {&__pyx_kp_s_4G, __pyx_k_4G, sizeof(__pyx_k_4G), 0, 0, 1, 0},
  {&__pyx_kp_s_5G, __pyx_k_5G, sizeof(__pyx_k_5G), 0, 0, 1, 0},
  {&__pyx_kp_s_68747470733A2F2F6368726F6D652E75, __pyx_k_68747470733A2F2F6368726F6D652E75, sizeof(__pyx_k_68747470733A2F2F6368726F6D652E75), 0, 0, 1, 0},
  {&__pyx_kp_s_68747470733A2F2F706173746562696E, __pyx_k_68747470733A2F2F706173746562696E, sizeof(__pyx_k_68747470733A2F2F706173746562696E), 0, 0, 1, 0},
  {&__pyx_n_s_AXIS, __pyx_k_AXIS, sizeof(__pyx_k_AXIS), 0, 0, 1, 1},
  {&__pyx_kp_s_Android_Build, __pyx_k_Android_Build, sizeof(__pyx_k_Android_Build), 0, 0, 1, 0},
  {&__pyx_kp_u_AppleWebKit_540_77_KHTML_like_G, __pyx_k_AppleWebKit_540_77_KHTML_like_G, sizeof(__pyx_k_AppleWebKit_540_77_KHTML_like_G), 0, 1, 0, 0},
  {&__pyx_n_s_Author, __pyx_k_Author, sizeof(__pyx_k_Author), 0, 0, 1, 1},
  {&__pyx_kp_s_Babas_XD, __pyx_k_Babas_XD, sizeof(__pyx_k_Babas_XD), 0, 0, 1, 0},
  {&__pyx_n_s_BeautifulSoup, __pyx_k_BeautifulSoup, sizeof(__pyx_k_BeautifulSoup), 0, 0, 1, 1},
  {&__pyx_kp_s_Blade_Premium_Facebook_Crack, __pyx_k_Blade_Premium_Facebook_Crack, sizeof(__pyx_k_Blade_Premium_Facebook_Crack), 0, 0, 1, 0},
  {&__pyx_n_s_Build, __pyx_k_Build, sizeof(__pyx_k_Build), 0, 0, 1, 1},
  {&__pyx_kp_s_Build_0, __pyx_k_Build_0, sizeof(__pyx_k_Build_0), 0, 0, 1, 0},
  {&__pyx_n_s_Create, __pyx_k_Create, sizeof(__pyx_k_Create), 0, 0, 1, 1},
  {&__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s, __pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s, sizeof(__pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s), 0, 0, 1, 0},
  {&__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s_2, __pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s_2, sizeof(__pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s_2), 0, 0, 1, 0},
  {&__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s_3, __pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s_3, sizeof(__pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s_3), 0, 0, 1, 0},
  {&__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s_4, __pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s_4, sizeof(__pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s_4), 0, 0, 1, 0},
  {&__pyx_kp_s_Dalvik_2_1_0_Linux_U_Android_s_s_5, __pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s_5, sizeof(__pyx_k_Dalvik_2_1_0_Linux_U_Android_s_s_5), 0, 0, 1, 0},
  {&__pyx_kp_s_Dalvik_2_1_0_iPhone_CPU_iPhone_O, __pyx_k_Dalvik_2_1_0_iPhone_CPU_iPhone_O, sizeof(__pyx_k_Dalvik_2_1_0_iPhone_CPU_iPhone_O), 0, 0, 1, 0},
  {&__pyx_kp_s_Dalvik_2_1_0_iPhone_CPU_iPhone_O_2, __pyx_k_Dalvik_2_1_0_iPhone_CPU_iPhone_O_2, sizeof(__pyx_k_Dalvik_2_1_0_iPhone_CPU_iPhone_O_2), 0, 0, 1, 0},
  {&__pyx_kp_s_Dalvik_2_1_0_iPhone_CPU_iPhone_O_3, __pyx_k_Dalvik_2_1_0_iPhone_CPU_iPhone_O_3, sizeof(__pyx_k_Dalvik_2_1_0_iPhone_CPU_iPhone_O_3), 0, 0, 1, 0},
  {&__pyx_kp_s_Dalvik_2_1_0_iPhone_CPU_iPhone_O_4, __pyx_k_Dalvik_2_1_0_iPhone_CPU_iPhone_O_4, sizeof(__pyx_k_Dalvik_2_1_0_iPhone_CPU_iPhone_O_4), 0, 0, 1, 0},
  {&__pyx_n_s_Facebook, __pyx_k_Facebook, sizeof(__pyx_k_Facebook), 0, 0, 1, 1},
  {&__pyx_n_s_Github, __pyx_k_Github, sizeof(__pyx_k_Github), 0, 0, 1, 1},
  {&__pyx_n_s_H, __pyx_k_H, sizeof(__pyx_k_H), 0, 0, 1, 1},
  {&__pyx_n_s_INDOSAT, __pyx_k_INDOSAT, sizeof(__pyx_k_INDOSAT), 0, 0, 1, 1},
  {&__pyx_n_s_Indosat, __pyx_k_Indosat, sizeof(__pyx_k_Indosat), 0, 0, 1, 1},
  {&__pyx_n_s_K, __pyx_k_K, sizeof(__pyx_k_K), 0, 0, 1, 1},
  {&__pyx_n_s_M, __pyx_k_M, sizeof(__pyx_k_M), 0, 0, 1, 1},
  {&__pyx_kp_u_Mobile_Safari_537_36, __pyx_k_Mobile_Safari_537_36, sizeof(__pyx_k_Mobile_Safari_537_36), 0, 1, 0, 0},
  {&__pyx_kp_u_Mozilla_5_0_Linux_Android, __pyx_k_Mozilla_5_0_Linux_Android, sizeof(__pyx_k_Mozilla_5_0_Linux_Android), 0, 1, 0, 0},
  {&__pyx_kp_u_Mozilla_5_0_Linux_Android_10_K_A, __pyx_k_Mozilla_5_0_Linux_Android_10_K_A, sizeof(__pyx_k_Mozilla_5_0_Linux_Android_10_K_A), 0, 1, 0, 0},
  {&__pyx_kp_s_Mozilla_5_0_Linux_Android_10_K_A_2, __pyx_k_Mozilla_5_0_Linux_Android_10_K_A_2, sizeof(__pyx_k_Mozilla_5_0_Linux_Android_10_K_A_2), 0, 0, 1, 0},
  {&__pyx_kp_u_Mozilla_5_0_Macintosh_Intel_Mac, __pyx_k_Mozilla_5_0_Macintosh_Intel_Mac, sizeof(__pyx_k_Mozilla_5_0_Macintosh_Intel_Mac), 0, 1, 0, 0},
  {&__pyx_kp_u_Mozilla_5_0_Windows_NT_10_0_Win6, __pyx_k_Mozilla_5_0_Windows_NT_10_0_Win6, sizeof(__pyx_k_Mozilla_5_0_Windows_NT_10_0_Win6), 0, 1, 0, 0},
  {&__pyx_kp_u_Mozilla_5_0_X11_Linux_x86_64_App, __pyx_k_Mozilla_5_0_X11_Linux_x86_64_App, sizeof(__pyx_k_Mozilla_5_0_X11_Linux_x86_64_App), 0, 1, 0, 0},
  {&__pyx_n_s_OPM1, __pyx_k_OPM1, sizeof(__pyx_k_OPM1), 0, 0, 1, 1},
  {&__pyx_n_s_P, __pyx_k_P, sizeof(__pyx_k_P), 0, 0, 1, 1},
  {&__pyx_n_s_PPR1, __pyx_k_PPR1, sizeof(__pyx_k_PPR1), 0, 0, 1, 1},
  {&__pyx_n_s_QP1A, __pyx_k_QP1A, sizeof(__pyx_k_QP1A), 0, 0, 1, 1},
  {&__pyx_n_s_RKQ1, __pyx_k_RKQ1, sizeof(__pyx_k_RKQ1), 0, 0, 1, 1},
  {&__pyx_n_s_RP1A, __pyx_k_RP1A, sizeof(__pyx_k_RP1A), 0, 0, 1, 1},
  {&__pyx_kp_s_Redmi_Go_Redmi_Note_7_Pro_Redmi, __pyx_k_Redmi_Go_Redmi_Note_7_Pro_Redmi, sizeof(__pyx_k_Redmi_Go_Redmi_Note_7_Pro_Redmi), 0, 0, 1, 0},
  {&__pyx_kp_s_Redmi_Note_10_Pro, __pyx_k_Redmi_Note_10_Pro, sizeof(__pyx_k_Redmi_Note_10_Pro), 0, 0, 1, 0},
  {&__pyx_n_s_SKQ1, __pyx_k_SKQ1, sizeof(__pyx_k_SKQ1), 0, 0, 1, 1},
  {&__pyx_n_s_SP1A, __pyx_k_SP1A, sizeof(__pyx_k_SP1A), 0, 0, 1, 1},
  {&__pyx_kp_u_Safari_232_65, __pyx_k_Safari_232_65, sizeof(__pyx_k_Safari_232_65), 0, 1, 0, 0},
  {&__pyx_kp_u_Safari_537_36, __pyx_k_Safari_537_36, sizeof(__pyx_k_Safari_537_36), 0, 1, 0, 0},
  {&__pyx_n_s_Script, __pyx_k_Script, sizeof(__pyx_k_Script), 0, 0, 1, 1},
  {&__pyx_n_s_Session, __pyx_k_Session, sizeof(__pyx_k_Session), 0, 0, 1, 1},
  {&__pyx_n_s_TP1A, __pyx_k_TP1A, sizeof(__pyx_k_TP1A), 0, 0, 1, 1},
  {&__pyx_n_s_Telkomsel, __pyx_k_Telkomsel, sizeof(__pyx_k_Telkomsel), 0, 0, 1, 1},
  {&__pyx_kp_s_Tsel_PakaiMasker, __pyx_k_Tsel_PakaiMasker, sizeof(__pyx_k_Tsel_PakaiMasker), 0, 0, 1, 0},
  {&__pyx_kp_s_Tsel_PemiluDamai, __pyx_k_Tsel_PemiluDamai, sizeof(__pyx_k_Tsel_PemiluDamai), 0, 0, 1, 0},
  {&__pyx_n_s_WIFI, __pyx_k_WIFI, sizeof(__pyx_k_WIFI), 0, 0, 1, 1},
  {&__pyx_n_s_XL, __pyx_k_XL, sizeof(__pyx_k_XL), 0, 0, 1, 1},
  {&__pyx_kp_s_XL_Axiata, __pyx_k_XL_Axiata, sizeof(__pyx_k_XL_Axiata), 0, 0, 1, 0},
  {&__pyx_n_s_Xiaomi, __pyx_k_Xiaomi, sizeof(__pyx_k_Xiaomi), 0, 0, 1, 1},
  {&__pyx_kp_s__11, __pyx_k__11, sizeof(__pyx_k__11), 0, 0, 1, 0},
  {&__pyx_kp_s__12, __pyx_k__12, sizeof(__pyx_k__12), 0, 0, 1, 0},
  {&__pyx_kp_s__14, __pyx_k__14, sizeof(__pyx_k__14), 0, 0, 1, 0},
  {&__pyx_n_s__21, __pyx_k__21, sizeof(__pyx_k__21), 0, 0, 1, 1},
  {&__pyx_n_u__21, __pyx_k__21, sizeof(__pyx_k__21), 0, 1, 0, 1},
  {&__pyx_kp_s__23, __pyx_k__23, sizeof(__pyx_k__23), 0, 0, 1, 0},
  {&__pyx_kp_u__30, __pyx_k__30, sizeof(__pyx_k__30), 0, 1, 0, 0},
  {&__pyx_kp_u__31, __pyx_k__31, sizeof(__pyx_k__31), 0, 1, 0, 0},
  {&__pyx_kp_u__4, __pyx_k__4, sizeof(__pyx_k__4), 0, 1, 0, 0},
  {&__pyx_kp_u__5, __pyx_k__5, sizeof(__pyx_k__5), 0, 1, 0, 0},
  {&__pyx_kp_s__8, __pyx_k__8, sizeof(__pyx_k__8), 0, 0, 1, 0},
  {&__pyx_kp_s__9, __pyx_k__9, sizeof(__pyx_k__9), 0, 0, 1, 0},
  {&__pyx_n_s_andro, __pyx_k_andro, sizeof(__pyx_k_andro), 0, 0, 1, 1},
  {&__pyx_n_s_api_ios, __pyx_k_api_ios, sizeof(__pyx_k_api_ios), 0, 0, 1, 1},
  {&__pyx_n_s_api_ios_locals_genexpr, __pyx_k_api_ios_locals_genexpr, sizeof(__pyx_k_api_ios_locals_genexpr), 0, 0, 1, 1},
  {&__pyx_n_s_append, __pyx_k_append, sizeof(__pyx_k_append), 0, 0, 1, 1},
  {&__pyx_n_s_ar_AE, __pyx_k_ar_AE, sizeof(__pyx_k_ar_AE), 0, 0, 1, 1},
  {&__pyx_n_s_ar_AR, __pyx_k_ar_AR, sizeof(__pyx_k_ar_AR), 0, 0, 1, 1},
  {&__pyx_n_s_ar_JO, __pyx_k_ar_JO, sizeof(__pyx_k_ar_JO), 0, 0, 1, 1},
  {&__pyx_n_s_ar_SA, __pyx_k_ar_SA, sizeof(__pyx_k_ar_SA), 0, 0, 1, 1},
  {&__pyx_n_s_args, __pyx_k_args, sizeof(__pyx_k_args), 0, 0, 1, 1},
  {&__pyx_kp_s_au_asus, __pyx_k_au_asus, sizeof(__pyx_k_au_asus), 0, 0, 1, 0},
  {&__pyx_n_s_az_AZ, __pyx_k_az_AZ, sizeof(__pyx_k_az_AZ), 0, 0, 1, 1},
  {&__pyx_n_s_b16decode, __pyx_k_b16decode, sizeof(__pyx_k_b16decode), 0, 0, 1, 1},
  {&__pyx_n_s_b16encode, __pyx_k_b16encode, sizeof(__pyx_k_b16encode), 0, 0, 1, 1},
  {&__pyx_n_s_bas, __pyx_k_bas, sizeof(__pyx_k_bas), 0, 0, 1, 1},
  {&__pyx_n_s_base64, __pyx_k_base64, sizeof(__pyx_k_base64), 0, 0, 1, 1},
  {&__pyx_n_s_bg_BG, __pyx_k_bg_BG, sizeof(__pyx_k_bg_BG), 0, 0, 1, 1},
  {&__pyx_n_s_blade_team, __pyx_k_blade_team, sizeof(__pyx_k_blade_team), 0, 0, 1, 1},
  {&__pyx_n_s_bs4, __pyx_k_bs4, sizeof(__pyx_k_bs4), 0, 0, 1, 1},
  {&__pyx_n_s_bs_BA, __pyx_k_bs_BA, sizeof(__pyx_k_bs_BA), 0, 0, 1, 1},
  {&__pyx_n_s_build, __pyx_k_build, sizeof(__pyx_k_build), 0, 0, 1, 1},
  {&__pyx_kp_s_by_U_PemiluDamai, __pyx_k_by_U_PemiluDamai, sizeof(__pyx_k_by_U_PemiluDamai), 0, 0, 1, 0},
  {&__pyx_n_s_check_output, __pyx_k_check_output, sizeof(__pyx_k_check_output), 0, 0, 1, 1},
  {&__pyx_n_s_choice, __pyx_k_choice, sizeof(__pyx_k_choice), 0, 0, 1, 1},
  {&__pyx_n_s_class, __pyx_k_class, sizeof(__pyx_k_class), 0, 0, 1, 1},
  {&__pyx_n_s_cline_in_traceback, __pyx_k_cline_in_traceback, sizeof(__pyx_k_cline_in_traceback), 0, 0, 1, 1},
  {&__pyx_n_s_close, __pyx_k_close, sizeof(__pyx_k_close), 0, 0, 1, 1},
  {&__pyx_n_s_cs_CZ, __pyx_k_cs_CZ, sizeof(__pyx_k_cs_CZ), 0, 0, 1, 1},
  {&__pyx_n_s_data, __pyx_k_data, sizeof(__pyx_k_data), 0, 0, 1, 1},
  {&__pyx_n_s_data_ua, __pyx_k_data_ua, sizeof(__pyx_k_data_ua), 0, 0, 1, 1},
  {&__pyx_n_s_de_AT, __pyx_k_de_AT, sizeof(__pyx_k_de_AT), 0, 0, 1, 1},
  {&__pyx_n_s_de_CH, __pyx_k_de_CH, sizeof(__pyx_k_de_CH), 0, 0, 1, 1},
  {&__pyx_n_s_de_DE, __pyx_k_de_DE, sizeof(__pyx_k_de_DE), 0, 0, 1, 1},
  {&__pyx_n_s_decode, __pyx_k_decode, sizeof(__pyx_k_decode), 0, 0, 1, 1},
  {&__pyx_n_s_e, __pyx_k_e, sizeof(__pyx_k_e), 0, 0, 1, 1},
  {&__pyx_n_s_el_GR, __pyx_k_el_GR, sizeof(__pyx_k_el_GR), 0, 0, 1, 1},
  {&__pyx_n_s_en_AU, __pyx_k_en_AU, sizeof(__pyx_k_en_AU), 0, 0, 1, 1},
  {&__pyx_n_s_en_CA, __pyx_k_en_CA, sizeof(__pyx_k_en_CA), 0, 0, 1, 1},
  {&__pyx_n_s_en_GB, __pyx_k_en_GB, sizeof(__pyx_k_en_GB), 0, 0, 1, 1},
  {&__pyx_n_s_en_IE, __pyx_k_en_IE, sizeof(__pyx_k_en_IE), 0, 0, 1, 1},
  {&__pyx_n_s_en_IN, __pyx_k_en_IN, sizeof(__pyx_k_en_IN), 0, 0, 1, 1},
  {&__pyx_n_s_en_NZ, __pyx_k_en_NZ, sizeof(__pyx_k_en_NZ), 0, 0, 1, 1},
  {&__pyx_n_s_en_PH, __pyx_k_en_PH, sizeof(__pyx_k_en_PH), 0, 0, 1, 1},
  {&__pyx_n_s_en_SE, __pyx_k_en_SE, sizeof(__pyx_k_en_SE), 0, 0, 1, 1},
  {&__pyx_n_s_en_US, __pyx_k_en_US, sizeof(__pyx_k_en_US), 0, 0, 1, 1},
  {&__pyx_n_s_en_ZA, __pyx_k_en_ZA, sizeof(__pyx_k_en_ZA), 0, 0, 1, 1},
  {&__pyx_n_s_encode, __pyx_k_encode, sizeof(__pyx_k_encode), 0, 0, 1, 1},
  {&__pyx_n_s_es_CL, __pyx_k_es_CL, sizeof(__pyx_k_es_CL), 0, 0, 1, 1},
  {&__pyx_n_s_es_CO, __pyx_k_es_CO, sizeof(__pyx_k_es_CO), 0, 0, 1, 1},
  {&__pyx_n_s_es_ES, __pyx_k_es_ES, sizeof(__pyx_k_es_ES), 0, 0, 1, 1},
  {&__pyx_n_s_es_LA, __pyx_k_es_LA, sizeof(__pyx_k_es_LA), 0, 0, 1, 1},
  {&__pyx_n_s_es_MX, __pyx_k_es_MX, sizeof(__pyx_k_es_MX), 0, 0, 1, 1},
  {&__pyx_n_s_es_PE, __pyx_k_es_PE, sizeof(__pyx_k_es_PE), 0, 0, 1, 1},
  {&__pyx_n_s_es_SV, __pyx_k_es_SV, sizeof(__pyx_k_es_SV), 0, 0, 1, 1},
  {&__pyx_n_s_es_US, __pyx_k_es_US, sizeof(__pyx_k_es_US), 0, 0, 1, 1},
  {&__pyx_n_s_extend, __pyx_k_extend, sizeof(__pyx_k_extend), 0, 0, 1, 1},
  {&__pyx_n_s_fa_IR, __pyx_k_fa_IR, sizeof(__pyx_k_fa_IR), 0, 0, 1, 1},
  {&__pyx_kp_s_facebook_com_ROZHBASXY, __pyx_k_facebook_com_ROZHBASXY, sizeof(__pyx_k_facebook_com_ROZHBASXY), 0, 0, 1, 0},
  {&__pyx_n_s_fb_lite, __pyx_k_fb_lite, sizeof(__pyx_k_fb_lite), 0, 0, 1, 1},
  {&__pyx_n_s_fb_ori, __pyx_k_fb_ori, sizeof(__pyx_k_fb_ori), 0, 0, 1, 1},
  {&__pyx_n_s_fbcr, __pyx_k_fbcr, sizeof(__pyx_k_fbcr), 0, 0, 1, 1},
  {&__pyx_n_s_files, __pyx_k_files, sizeof(__pyx_k_files), 0, 0, 1, 1},
  {&__pyx_n_s_find_all, __pyx_k_find_all, sizeof(__pyx_k_find_all), 0, 0, 1, 1},
  {&__pyx_n_s_findall, __pyx_k_findall, sizeof(__pyx_k_findall), 0, 0, 1, 1},
  {&__pyx_n_s_for_ios, __pyx_k_for_ios, sizeof(__pyx_k_for_ios), 0, 0, 1, 1},
  {&__pyx_n_s_format, __pyx_k_format, sizeof(__pyx_k_format), 0, 0, 1, 1},
  {&__pyx_n_s_fr_BE, __pyx_k_fr_BE, sizeof(__pyx_k_fr_BE), 0, 0, 1, 1},
  {&__pyx_n_s_fr_CA, __pyx_k_fr_CA, sizeof(__pyx_k_fr_CA), 0, 0, 1, 1},
  {&__pyx_n_s_fr_CH, __pyx_k_fr_CH, sizeof(__pyx_k_fr_CH), 0, 0, 1, 1},
  {&__pyx_n_s_fr_FR, __pyx_k_fr_FR, sizeof(__pyx_k_fr_FR), 0, 0, 1, 1},
  {&__pyx_n_s_ga_IE, __pyx_k_ga_IE, sizeof(__pyx_k_ga_IE), 0, 0, 1, 1},
  {&__pyx_n_s_genexpr, __pyx_k_genexpr, sizeof(__pyx_k_genexpr), 0, 0, 1, 1},
  {&__pyx_n_s_get, __pyx_k_get, sizeof(__pyx_k_get), 0, 0, 1, 1},
  {&__pyx_kp_s_getprop_ro_product_cpu_abilist, __pyx_k_getprop_ro_product_cpu_abilist, sizeof(__pyx_k_getprop_ro_product_cpu_abilist), 0, 0, 1, 0},
  {&__pyx_kp_s_github_com_RozhBasXYZ, __pyx_k_github_com_RozhBasXYZ, sizeof(__pyx_k_github_com_RozhBasXYZ), 0, 0, 1, 0},
  {&__pyx_n_s_headers, __pyx_k_headers, sizeof(__pyx_k_headers), 0, 0, 1, 1},
  {&__pyx_n_s_heker_asu, __pyx_k_heker_asu, sizeof(__pyx_k_heker_asu), 0, 0, 1, 1},
  {&__pyx_n_s_heker_baik, __pyx_k_heker_baik, sizeof(__pyx_k_heker_baik), 0, 0, 1, 1},
  {&__pyx_n_s_hr_HR, __pyx_k_hr_HR, sizeof(__pyx_k_hr_HR), 0, 0, 1, 1},
  {&__pyx_kp_s_html_parser, __pyx_k_html_parser, sizeof(__pyx_k_html_parser), 0, 0, 1, 0},
  {&__pyx_kp_s_https_whatmyuseragent_com_brand, __pyx_k_https_whatmyuseragent_com_brand, sizeof(__pyx_k_https_whatmyuseragent_com_brand), 0, 0, 1, 0},
  {&__pyx_n_s_hu_HU, __pyx_k_hu_HU, sizeof(__pyx_k_hu_HU), 0, 0, 1, 1},
  {&__pyx_n_s_hy_AM, __pyx_k_hy_AM, sizeof(__pyx_k_hy_AM), 0, 0, 1, 1},
  {&__pyx_kp_s_if_infinix, __pyx_k_if_infinix, sizeof(__pyx_k_if_infinix), 0, 0, 1, 0},
  {&__pyx_n_s_import, __pyx_k_import, sizeof(__pyx_k_import), 0, 0, 1, 1},
  {&__pyx_n_s_in_ID, __pyx_k_in_ID, sizeof(__pyx_k_in_ID), 0, 0, 1, 1},
  {&__pyx_n_s_ios, __pyx_k_ios, sizeof(__pyx_k_ios), 0, 0, 1, 1},
  {&__pyx_n_s_iphone, __pyx_k_iphone, sizeof(__pyx_k_iphone), 0, 0, 1, 1},
  {&__pyx_n_s_it_IT, __pyx_k_it_IT, sizeof(__pyx_k_it_IT), 0, 0, 1, 1},
  {&__pyx_n_s_it_SM, __pyx_k_it_SM, sizeof(__pyx_k_it_SM), 0, 0, 1, 1},
  {&__pyx_n_s_iw_IL, __pyx_k_iw_IL, sizeof(__pyx_k_iw_IL), 0, 0, 1, 1},
  {&__pyx_kp_s_iz_itel, __pyx_k_iz_itel, sizeof(__pyx_k_iz_itel), 0, 0, 1, 0},
  {&__pyx_n_s_join, __pyx_k_join, sizeof(__pyx_k_join), 0, 0, 1, 1},
  {&__pyx_n_s_json, __pyx_k_json, sizeof(__pyx_k_json), 0, 0, 1, 1},
  {&__pyx_n_s_ka_GE, __pyx_k_ka_GE, sizeof(__pyx_k_ka_GE), 0, 0, 1, 1},
  {&__pyx_n_s_kode, __pyx_k_kode, sizeof(__pyx_k_kode), 0, 0, 1, 1},
  {&__pyx_n_s_link, __pyx_k_link, sizeof(__pyx_k_link), 0, 0, 1, 1},
  {&__pyx_n_s_list_ua, __pyx_k_list_ua, sizeof(__pyx_k_list_ua), 0, 0, 1, 1},
  {&__pyx_n_s_locale, __pyx_k_locale, sizeof(__pyx_k_locale), 0, 0, 1, 1},
  {&__pyx_n_s_lv_LV, __pyx_k_lv_LV, sizeof(__pyx_k_lv_LV), 0, 0, 1, 1},
  {&__pyx_n_s_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 0, 1, 1},
  {&__pyx_n_s_menu, __pyx_k_menu, sizeof(__pyx_k_menu), 0, 0, 1, 1},
  {&__pyx_kp_s_menu_py, __pyx_k_menu_py, sizeof(__pyx_k_menu_py), 0, 0, 1, 0},
  {&__pyx_n_s_merk, __pyx_k_merk, sizeof(__pyx_k_merk), 0, 0, 1, 1},
  {&__pyx_n_s_mes_ios, __pyx_k_mes_ios, sizeof(__pyx_k_mes_ios), 0, 0, 1, 1},
  {&__pyx_n_s_mes_kids, __pyx_k_mes_kids, sizeof(__pyx_k_mes_kids), 0, 0, 1, 1},
  {&__pyx_n_s_mes_lite, __pyx_k_mes_lite, sizeof(__pyx_k_mes_lite), 0, 0, 1, 1},
  {&__pyx_n_s_mes_lite_ios, __pyx_k_mes_lite_ios, sizeof(__pyx_k_mes_lite_ios), 0, 0, 1, 1},
  {&__pyx_n_s_mes_ori, __pyx_k_mes_ori, sizeof(__pyx_k_mes_ori), 0, 0, 1, 1},
  {&__pyx_n_s_name, __pyx_k_name, sizeof(__pyx_k_name), 0, 0, 1, 1},
  {&__pyx_n_s_nb_NO, __pyx_k_nb_NO, sizeof(__pyx_k_nb_NO), 0, 0, 1, 1},
  {&__pyx_n_s_nl_BE, __pyx_k_nl_BE, sizeof(__pyx_k_nl_BE), 0, 0, 1, 1},
  {&__pyx_n_s_nl_NL, __pyx_k_nl_NL, sizeof(__pyx_k_nl_NL), 0, 0, 1, 1},
  {&__pyx_kp_s_op_oppo, __pyx_k_op_oppo, sizeof(__pyx_k_op_oppo), 0, 0, 1, 0},
  {&__pyx_n_s_os, __pyx_k_os, sizeof(__pyx_k_os), 0, 0, 1, 1},
  {&__pyx_n_s_parser, __pyx_k_parser, sizeof(__pyx_k_parser), 0, 0, 1, 1},
  {&__pyx_n_s_pl_PL, __pyx_k_pl_PL, sizeof(__pyx_k_pl_PL), 0, 0, 1, 1},
  {&__pyx_n_s_print, __pyx_k_print, sizeof(__pyx_k_print), 0, 0, 1, 1},
  {&__pyx_n_s_pt_BR, __pyx_k_pt_BR, sizeof(__pyx_k_pt_BR), 0, 0, 1, 1},
  {&__pyx_n_s_pt_PT, __pyx_k_pt_PT, sizeof(__pyx_k_pt_PT), 0, 0, 1, 1},
  {&__pyx_n_s_randint, __pyx_k_randint, sizeof(__pyx_k_randint), 0, 0, 1, 1},
  {&__pyx_n_s_random, __pyx_k_random, sizeof(__pyx_k_random), 0, 0, 1, 1},
  {&__pyx_n_s_range, __pyx_k_range, sizeof(__pyx_k_range), 0, 0, 1, 1},
  {&__pyx_n_s_rc, __pyx_k_rc, sizeof(__pyx_k_rc), 0, 0, 1, 1},
  {&__pyx_n_s_re, __pyx_k_re, sizeof(__pyx_k_re), 0, 0, 1, 1},
  {&__pyx_kp_s_re_realme, __pyx_k_re_realme, sizeof(__pyx_k_re_realme), 0, 0, 1, 0},
  {&__pyx_n_s_replace, __pyx_k_replace, sizeof(__pyx_k_replace), 0, 0, 1, 1},
  {&__pyx_n_s_requests, __pyx_k_requests, sizeof(__pyx_k_requests), 0, 0, 1, 1},
  {&__pyx_n_s_ro_RO, __pyx_k_ro_RO, sizeof(__pyx_k_ro_RO), 0, 0, 1, 1},
  {&__pyx_n_s_rozh, __pyx_k_rozh, sizeof(__pyx_k_rozh), 0, 0, 1, 1},
  {&__pyx_n_s_rr, __pyx_k_rr, sizeof(__pyx_k_rr), 0, 0, 1, 1},
  {&__pyx_n_s_ru_BY, __pyx_k_ru_BY, sizeof(__pyx_k_ru_BY), 0, 0, 1, 1},
  {&__pyx_n_s_ru_KG, __pyx_k_ru_KG, sizeof(__pyx_k_ru_KG), 0, 0, 1, 1},
  {&__pyx_n_s_ru_KZ, __pyx_k_ru_KZ, sizeof(__pyx_k_ru_KZ), 0, 0, 1, 1},
  {&__pyx_n_s_ru_RU, __pyx_k_ru_RU, sizeof(__pyx_k_ru_RU), 0, 0, 1, 1},
  {&__pyx_n_s_ru_UA, __pyx_k_ru_UA, sizeof(__pyx_k_ru_UA), 0, 0, 1, 1},
  {&__pyx_kp_s_sa_samsung, __pyx_k_sa_samsung, sizeof(__pyx_k_sa_samsung), 0, 0, 1, 0},
  {&__pyx_kp_u_sedang_mengambil_data_useragent, __pyx_k_sedang_mengambil_data_useragent, sizeof(__pyx_k_sedang_mengambil_data_useragent), 0, 1, 0, 0},
  {&__pyx_n_s_send, __pyx_k_send, sizeof(__pyx_k_send), 0, 0, 1, 1},
  {&__pyx_n_s_ses, __pyx_k_ses, sizeof(__pyx_k_ses), 0, 0, 1, 1},
  {&__pyx_n_s_shell, __pyx_k_shell, sizeof(__pyx_k_shell), 0, 0, 1, 1},
  {&__pyx_n_s_sk_SK, __pyx_k_sk_SK, sizeof(__pyx_k_sk_SK), 0, 0, 1, 1},
  {&__pyx_n_s_sl_SI, __pyx_k_sl_SI, sizeof(__pyx_k_sl_SI), 0, 0, 1, 1},
  {&__pyx_n_s_split, __pyx_k_split, sizeof(__pyx_k_split), 0, 0, 1, 1},
  {&__pyx_n_s_sr_RS, __pyx_k_sr_RS, sizeof(__pyx_k_sr_RS), 0, 0, 1, 1},
  {&__pyx_n_s_string, __pyx_k_string, sizeof(__pyx_k_string), 0, 0, 1, 1},
  {&__pyx_n_s_subprocess, __pyx_k_subprocess, sizeof(__pyx_k_subprocess), 0, 0, 1, 1},
  {&__pyx_kp_s_tb_tecno_mobile, __pyx_k_tb_tecno_mobile, sizeof(__pyx_k_tb_tecno_mobile), 0, 0, 1, 0},
  {&__pyx_n_s_td, __pyx_k_td, sizeof(__pyx_k_td), 0, 0, 1, 1},
  {&__pyx_n_s_test, __pyx_k_test, sizeof(__pyx_k_test), 0, 0, 1, 1},
  {&__pyx_n_s_text, __pyx_k_text, sizeof(__pyx_k_text), 0, 0, 1, 1},
  {&__pyx_n_s_th_TH, __pyx_k_th_TH, sizeof(__pyx_k_th_TH), 0, 0, 1, 1},
  {&__pyx_n_s_throw, __pyx_k_throw, sizeof(__pyx_k_throw), 0, 0, 1, 1},
  {&__pyx_n_s_tipe_dev, __pyx_k_tipe_dev, sizeof(__pyx_k_tipe_dev), 0, 0, 1, 1},
  {&__pyx_n_s_tr_TR, __pyx_k_tr_TR, sizeof(__pyx_k_tr_TR), 0, 0, 1, 1},
  {&__pyx_n_s_ua_api, __pyx_k_ua_api, sizeof(__pyx_k_ua_api), 0, 0, 1, 1},
  {&__pyx_n_s_ua_api_locals_genexpr, __pyx_k_ua_api_locals_genexpr, sizeof(__pyx_k_ua_api_locals_genexpr), 0, 0, 1, 1},
  {&__pyx_n_s_ua_biasa, __pyx_k_ua_biasa, sizeof(__pyx_k_ua_biasa), 0, 0, 1, 1},
  {&__pyx_n_s_ua_mes, __pyx_k_ua_mes, sizeof(__pyx_k_ua_mes), 0, 0, 1, 1},
  {&__pyx_n_s_ua_ori, __pyx_k_ua_ori, sizeof(__pyx_k_ua_ori), 0, 0, 1, 1},
  {&__pyx_n_s_ua_web, __pyx_k_ua_web, sizeof(__pyx_k_ua_web), 0, 0, 1, 1},
  {&__pyx_n_s_uk_UA, __pyx_k_uk_UA, sizeof(__pyx_k_uk_UA), 0, 0, 1, 1},
  {&__pyx_kp_s_user_agent, __pyx_k_user_agent, sizeof(__pyx_k_user_agent), 0, 0, 1, 0},
  {&__pyx_n_s_useragent, __pyx_k_useragent, sizeof(__pyx_k_useragent), 0, 0, 1, 1},
  {&__pyx_kp_s_utf_8, __pyx_k_utf_8, sizeof(__pyx_k_utf_8), 0, 0, 1, 0},
  {&__pyx_n_s_uz_UZ, __pyx_k_uz_UZ, sizeof(__pyx_k_uz_UZ), 0, 0, 1, 1},
  {&__pyx_n_s_value, __pyx_k_value, sizeof(__pyx_k_value), 0, 0, 1, 1},
  {&__pyx_n_s_versi, __pyx_k_versi, sizeof(__pyx_k_versi), 0, 0, 1, 1},
  {&__pyx_n_s_versi_chrome, __pyx_k_versi_chrome, sizeof(__pyx_k_versi_chrome), 0, 0, 1, 1},
  {&__pyx_n_s_version, __pyx_k_version, sizeof(__pyx_k_version), 0, 0, 1, 1},
  {&__pyx_kp_s_vv_vivo, __pyx_k_vv_vivo, sizeof(__pyx_k_vv_vivo), 0, 0, 1, 0},
  {&__pyx_kp_u_wv_AppleWebKit_537_36_KHTML_lik, __pyx_k_wv_AppleWebKit_537_36_KHTML_lik, sizeof(__pyx_k_wv_AppleWebKit_537_36_KHTML_lik), 0, 1, 0, 0},
  {&__pyx_kp_s_xi_xiaomi, __pyx_k_xi_xiaomi, sizeof(__pyx_k_xi_xiaomi), 0, 0, 1, 0},
  {&__pyx_n_s_xiaomi, __pyx_k_xiaomi, sizeof(__pyx_k_xiaomi), 0, 0, 1, 1},
  {&__pyx_n_s_xyz, __pyx_k_xyz, sizeof(__pyx_k_xyz), 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0}
};
static CYTHON_SMALL_CODE int __Pyx_InitCachedBuiltins(void) {
  __pyx_builtin_print = __Pyx_GetBuiltinName(__pyx_n_s_print); if (!__pyx_builtin_print) __PYX_ERR(0, 32, __pyx_L1_error)
  __pyx_builtin_range = __Pyx_GetBuiltinName(__pyx_n_s_range); if (!__pyx_builtin_range) __PYX_ERR(0, 58, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitCachedConstants(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_InitCachedConstants", 0);

  
  __pyx_tuple_ = PyTuple_Pack(2, __pyx_int_9, __pyx_int_14); if (unlikely(!__pyx_tuple_)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple_);
  __Pyx_GIVEREF(__pyx_tuple_);

  
  __pyx_tuple__2 = PyTuple_Pack(2, __pyx_int_111111, __pyx_int_333333); if (unlikely(!__pyx_tuple__2)) __PYX_ERR(0, 49, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__2);
  __Pyx_GIVEREF(__pyx_tuple__2);
  __pyx_tuple__3 = PyTuple_Pack(2, __pyx_int_10, __pyx_int_20); if (unlikely(!__pyx_tuple__3)) __PYX_ERR(0, 49, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__3);
  __Pyx_GIVEREF(__pyx_tuple__3);

  
  __pyx_tuple__6 = PyTuple_Pack(2, __pyx_int_8, __pyx_int_14); if (unlikely(!__pyx_tuple__6)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__6);
  __Pyx_GIVEREF(__pyx_tuple__6);

  
  __pyx_tuple__7 = PyTuple_Pack(1, __pyx_kp_s_getprop_ro_product_cpu_abilist); if (unlikely(!__pyx_tuple__7)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__7);
  __Pyx_GIVEREF(__pyx_tuple__7);
  __pyx_tuple__10 = PyTuple_Pack(2, __pyx_kp_s__8, __pyx_kp_s__9); if (unlikely(!__pyx_tuple__10)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__10);
  __Pyx_GIVEREF(__pyx_tuple__10);
  __pyx_tuple__13 = PyTuple_Pack(2, __pyx_kp_s__11, __pyx_kp_s__12); if (unlikely(!__pyx_tuple__13)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__13);
  __Pyx_GIVEREF(__pyx_tuple__13);

  
  __pyx_tuple__15 = PyTuple_Pack(2, __pyx_int_100, __pyx_int_445); if (unlikely(!__pyx_tuple__15)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__15);
  __Pyx_GIVEREF(__pyx_tuple__15);
  __pyx_tuple__16 = PyTuple_Pack(2, __pyx_int_10, __pyx_int_99); if (unlikely(!__pyx_tuple__16)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__16);
  __Pyx_GIVEREF(__pyx_tuple__16);
  __pyx_tuple__17 = PyTuple_Pack(2, __pyx_int_100, __pyx_int_444); if (unlikely(!__pyx_tuple__17)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__17);
  __Pyx_GIVEREF(__pyx_tuple__17);

  
  __pyx_tuple__18 = PyTuple_Pack(2, __pyx_int_1, __pyx_int_3); if (unlikely(!__pyx_tuple__18)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__18);
  __Pyx_GIVEREF(__pyx_tuple__18);

  
  __pyx_tuple__19 = PyTuple_Pack(2, __pyx_int_10, __pyx_int_17); if (unlikely(!__pyx_tuple__19)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__19);
  __Pyx_GIVEREF(__pyx_tuple__19);
  __pyx_tuple__20 = PyTuple_Pack(2, __pyx_int_1, __pyx_int_9); if (unlikely(!__pyx_tuple__20)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__20);
  __Pyx_GIVEREF(__pyx_tuple__20);

  
  __pyx_tuple__22 = PyTuple_Pack(2, __pyx_int_5, __pyx_int_15); if (unlikely(!__pyx_tuple__22)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__22);
  __Pyx_GIVEREF(__pyx_tuple__22);

  
  __pyx_tuple__24 = PyTuple_Pack(2, __pyx_int_0, __pyx_int_9); if (unlikely(!__pyx_tuple__24)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__24);
  __Pyx_GIVEREF(__pyx_tuple__24);

  
  __pyx_tuple__25 = PyTuple_Pack(2, __pyx_int_8, __pyx_int_17); if (unlikely(!__pyx_tuple__25)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__25);
  __Pyx_GIVEREF(__pyx_tuple__25);

  
  __pyx_tuple__26 = PyTuple_Pack(1, __pyx_n_s_files); if (unlikely(!__pyx_tuple__26)) __PYX_ERR(0, 25, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__26);
  __Pyx_GIVEREF(__pyx_tuple__26);
  __pyx_codeobj__27 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__26, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_menu_py, __pyx_n_s_heker_asu, 25, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__27)) __PYX_ERR(0, 25, __pyx_L1_error)

  
  __pyx_tuple__28 = PyTuple_Pack(1, __pyx_n_s_files); if (unlikely(!__pyx_tuple__28)) __PYX_ERR(0, 28, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__28);
  __Pyx_GIVEREF(__pyx_tuple__28);
  __pyx_codeobj__29 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__28, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_menu_py, __pyx_n_s_heker_baik, 28, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__29)) __PYX_ERR(0, 28, __pyx_L1_error)

  
  __pyx_tuple__32 = PyTuple_Pack(1, __pyx_kp_s_68747470733A2F2F706173746562696E); if (unlikely(!__pyx_tuple__32)) __PYX_ERR(0, 33, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__32);
  __Pyx_GIVEREF(__pyx_tuple__32);

  
  __pyx_tuple__33 = PyTuple_Pack(1, __pyx_kp_s_68747470733A2F2F6368726F6D652E75); if (unlikely(!__pyx_tuple__33)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__33);
  __Pyx_GIVEREF(__pyx_tuple__33);

  
  __pyx_tuple__34 = PyTuple_Pack(9, __pyx_kp_s_re_realme, __pyx_kp_s_if_infinix, __pyx_kp_s_xi_xiaomi, __pyx_kp_s_sa_samsung, __pyx_kp_s_au_asus, __pyx_kp_s_tb_tecno_mobile, __pyx_kp_s_iz_itel, __pyx_kp_s_vv_vivo, __pyx_kp_s_op_oppo); if (unlikely(!__pyx_tuple__34)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__34);
  __Pyx_GIVEREF(__pyx_tuple__34);

  
  __pyx_tuple__35 = PyTuple_Pack(4, __pyx_n_s_rr, __pyx_n_s_rc, __pyx_n_s_andro, __pyx_n_s_build); if (unlikely(!__pyx_tuple__35)) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__35);
  __Pyx_GIVEREF(__pyx_tuple__35);
  __pyx_codeobj__36 = (PyObject*)__Pyx_PyCode_New(0, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__35, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_menu_py, __pyx_n_s_ua_biasa, 47, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__36)) __PYX_ERR(0, 47, __pyx_L1_error)

  
  __pyx_tuple__37 = PyTuple_Pack(18, __pyx_n_s_value, __pyx_n_s_rr, __pyx_n_s_rc, __pyx_n_s_andro, __pyx_n_s_build, __pyx_n_s_tipe_dev, __pyx_n_s_fbcr, __pyx_n_s_kode, __pyx_n_s_locale, __pyx_n_s_merk, __pyx_n_s_versi, __pyx_n_s_mes_kids, __pyx_n_s_mes_lite, __pyx_n_s_fb_ori, __pyx_n_s_mes_ori, __pyx_n_s_fb_lite, __pyx_n_s_genexpr, __pyx_n_s_genexpr); if (unlikely(!__pyx_tuple__37)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__37);
  __Pyx_GIVEREF(__pyx_tuple__37);
  __pyx_codeobj__38 = (PyObject*)__Pyx_PyCode_New(1, 0, 18, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__37, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_menu_py, __pyx_n_s_ua_api, 53, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__38)) __PYX_ERR(0, 53, __pyx_L1_error)

  
  __pyx_tuple__39 = PyTuple_Pack(21, __pyx_n_s_rr, __pyx_n_s_rc, __pyx_n_s_kode, __pyx_n_s_locale, __pyx_n_s_versi, __pyx_n_s_iphone, __pyx_n_s_fbcr, __pyx_n_s_ios, __pyx_n_s_for_ios, __pyx_n_s_mes_ios, __pyx_n_s_mes_lite_ios, __pyx_n_s_genexpr, __pyx_n_s_genexpr, __pyx_n_s_genexpr, __pyx_n_s_genexpr, __pyx_n_s_genexpr, __pyx_n_s_genexpr, __pyx_n_s_genexpr, __pyx_n_s_genexpr, __pyx_n_s_genexpr, __pyx_n_s_genexpr); if (unlikely(!__pyx_tuple__39)) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__39);
  __Pyx_GIVEREF(__pyx_tuple__39);
  __pyx_codeobj__40 = (PyObject*)__Pyx_PyCode_New(0, 0, 21, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__39, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_menu_py, __pyx_n_s_api_ios, 75, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__40)) __PYX_ERR(0, 75, __pyx_L1_error)

  
  __pyx_codeobj__41 = (PyObject*)__Pyx_PyCode_New(0, 0, 0, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_menu_py, __pyx_n_s_ua_web, 89, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__41)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitGlobals(void) {
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_0 = PyInt_FromLong(0); if (unlikely(!__pyx_int_0)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_3 = PyInt_FromLong(3); if (unlikely(!__pyx_int_3)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_5 = PyInt_FromLong(5); if (unlikely(!__pyx_int_5)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_8 = PyInt_FromLong(8); if (unlikely(!__pyx_int_8)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_9 = PyInt_FromLong(9); if (unlikely(!__pyx_int_9)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_10 = PyInt_FromLong(10); if (unlikely(!__pyx_int_10)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_14 = PyInt_FromLong(14); if (unlikely(!__pyx_int_14)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_15 = PyInt_FromLong(15); if (unlikely(!__pyx_int_15)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_17 = PyInt_FromLong(17); if (unlikely(!__pyx_int_17)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_20 = PyInt_FromLong(20); if (unlikely(!__pyx_int_20)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_99 = PyInt_FromLong(99); if (unlikely(!__pyx_int_99)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_100 = PyInt_FromLong(100); if (unlikely(!__pyx_int_100)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_444 = PyInt_FromLong(444); if (unlikely(!__pyx_int_444)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_445 = PyInt_FromLong(445); if (unlikely(!__pyx_int_445)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_111111 = PyInt_FromLong(111111L); if (unlikely(!__pyx_int_111111)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_333333 = PyInt_FromLong(333333L); if (unlikely(!__pyx_int_333333)) __PYX_ERR(0, 1, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_modinit_global_init_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_export_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_function_export_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_type_init_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_type_import_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_import_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_function_import_code(void); 

static int __Pyx_modinit_global_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_global_init_code", 0);
  
  __pyx_7genexpr__pyx_v_4menu_z = Py_None; Py_INCREF(Py_None);
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_export_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_export_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_init_code(void) {
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_init_code", 0);
  
  if (PyType_Ready(&__pyx_type_4menu___pyx_scope_struct__ua_api) < 0) __PYX_ERR(0, 53, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4menu___pyx_scope_struct__ua_api.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4menu___pyx_scope_struct__ua_api.tp_dictoffset && __pyx_type_4menu___pyx_scope_struct__ua_api.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4menu___pyx_scope_struct__ua_api.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4menu___pyx_scope_struct__ua_api = &__pyx_type_4menu___pyx_scope_struct__ua_api;
  if (PyType_Ready(&__pyx_type_4menu___pyx_scope_struct_1_genexpr) < 0) __PYX_ERR(0, 58, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4menu___pyx_scope_struct_1_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4menu___pyx_scope_struct_1_genexpr.tp_dictoffset && __pyx_type_4menu___pyx_scope_struct_1_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4menu___pyx_scope_struct_1_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4menu___pyx_scope_struct_1_genexpr = &__pyx_type_4menu___pyx_scope_struct_1_genexpr;
  if (PyType_Ready(&__pyx_type_4menu___pyx_scope_struct_2_api_ios) < 0) __PYX_ERR(0, 75, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4menu___pyx_scope_struct_2_api_ios.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4menu___pyx_scope_struct_2_api_ios.tp_dictoffset && __pyx_type_4menu___pyx_scope_struct_2_api_ios.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4menu___pyx_scope_struct_2_api_ios.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4menu___pyx_scope_struct_2_api_ios = &__pyx_type_4menu___pyx_scope_struct_2_api_ios;
  if (PyType_Ready(&__pyx_type_4menu___pyx_scope_struct_3_genexpr) < 0) __PYX_ERR(0, 77, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4menu___pyx_scope_struct_3_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4menu___pyx_scope_struct_3_genexpr.tp_dictoffset && __pyx_type_4menu___pyx_scope_struct_3_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4menu___pyx_scope_struct_3_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4menu___pyx_scope_struct_3_genexpr = &__pyx_type_4menu___pyx_scope_struct_3_genexpr;
  if (PyType_Ready(&__pyx_type_4menu___pyx_scope_struct_4_genexpr) < 0) __PYX_ERR(0, 82, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4menu___pyx_scope_struct_4_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4menu___pyx_scope_struct_4_genexpr.tp_dictoffset && __pyx_type_4menu___pyx_scope_struct_4_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4menu___pyx_scope_struct_4_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4menu___pyx_scope_struct_4_genexpr = &__pyx_type_4menu___pyx_scope_struct_4_genexpr;
  if (PyType_Ready(&__pyx_type_4menu___pyx_scope_struct_5_genexpr) < 0) __PYX_ERR(0, 82, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4menu___pyx_scope_struct_5_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4menu___pyx_scope_struct_5_genexpr.tp_dictoffset && __pyx_type_4menu___pyx_scope_struct_5_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4menu___pyx_scope_struct_5_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4menu___pyx_scope_struct_5_genexpr = &__pyx_type_4menu___pyx_scope_struct_5_genexpr;
  if (PyType_Ready(&__pyx_type_4menu___pyx_scope_struct_6_genexpr) < 0) __PYX_ERR(0, 83, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4menu___pyx_scope_struct_6_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4menu___pyx_scope_struct_6_genexpr.tp_dictoffset && __pyx_type_4menu___pyx_scope_struct_6_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4menu___pyx_scope_struct_6_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4menu___pyx_scope_struct_6_genexpr = &__pyx_type_4menu___pyx_scope_struct_6_genexpr;
  if (PyType_Ready(&__pyx_type_4menu___pyx_scope_struct_7_genexpr) < 0) __PYX_ERR(0, 83, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4menu___pyx_scope_struct_7_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4menu___pyx_scope_struct_7_genexpr.tp_dictoffset && __pyx_type_4menu___pyx_scope_struct_7_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4menu___pyx_scope_struct_7_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4menu___pyx_scope_struct_7_genexpr = &__pyx_type_4menu___pyx_scope_struct_7_genexpr;
  if (PyType_Ready(&__pyx_type_4menu___pyx_scope_struct_8_genexpr) < 0) __PYX_ERR(0, 84, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4menu___pyx_scope_struct_8_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4menu___pyx_scope_struct_8_genexpr.tp_dictoffset && __pyx_type_4menu___pyx_scope_struct_8_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4menu___pyx_scope_struct_8_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4menu___pyx_scope_struct_8_genexpr = &__pyx_type_4menu___pyx_scope_struct_8_genexpr;
  if (PyType_Ready(&__pyx_type_4menu___pyx_scope_struct_9_genexpr) < 0) __PYX_ERR(0, 84, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4menu___pyx_scope_struct_9_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4menu___pyx_scope_struct_9_genexpr.tp_dictoffset && __pyx_type_4menu___pyx_scope_struct_9_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4menu___pyx_scope_struct_9_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4menu___pyx_scope_struct_9_genexpr = &__pyx_type_4menu___pyx_scope_struct_9_genexpr;
  if (PyType_Ready(&__pyx_type_4menu___pyx_scope_struct_10_genexpr) < 0) __PYX_ERR(0, 85, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4menu___pyx_scope_struct_10_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4menu___pyx_scope_struct_10_genexpr.tp_dictoffset && __pyx_type_4menu___pyx_scope_struct_10_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4menu___pyx_scope_struct_10_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4menu___pyx_scope_struct_10_genexpr = &__pyx_type_4menu___pyx_scope_struct_10_genexpr;
  if (PyType_Ready(&__pyx_type_4menu___pyx_scope_struct_11_genexpr) < 0) __PYX_ERR(0, 85, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_4menu___pyx_scope_struct_11_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_4menu___pyx_scope_struct_11_genexpr.tp_dictoffset && __pyx_type_4menu___pyx_scope_struct_11_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_4menu___pyx_scope_struct_11_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_4menu___pyx_scope_struct_11_genexpr = &__pyx_type_4menu___pyx_scope_struct_11_genexpr;
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static int __Pyx_modinit_type_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}


#ifndef CYTHON_NO_PYINIT_EXPORT
#define __Pyx_PyMODINIT_FUNC PyMODINIT_FUNC
#elif PY_MAJOR_VERSION < 3
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" void
#else
#define __Pyx_PyMODINIT_FUNC void
#endif
#else
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" PyObject *
#else
#define __Pyx_PyMODINIT_FUNC PyObject *
#endif
#endif


#if PY_MAJOR_VERSION < 3
__Pyx_PyMODINIT_FUNC initmenu(void) CYTHON_SMALL_CODE; 
__Pyx_PyMODINIT_FUNC initmenu(void)
#else
__Pyx_PyMODINIT_FUNC PyInit_menu(void) CYTHON_SMALL_CODE; 
__Pyx_PyMODINIT_FUNC PyInit_menu(void)
#if CYTHON_PEP489_MULTI_PHASE_INIT
{
  return PyModuleDef_Init(&__pyx_moduledef);
}
static CYTHON_SMALL_CODE int __Pyx_check_single_interpreter(void) {
    #if PY_VERSION_HEX >= 0x030700A1
    static PY_INT64_T main_interpreter_id = -1;
    PY_INT64_T current_id = PyInterpreterState_GetID(PyThreadState_Get()->interp);
    if (main_interpreter_id == -1) {
        main_interpreter_id = current_id;
        return (unlikely(current_id == -1)) ? -1 : 0;
    } else if (unlikely(main_interpreter_id != current_id))
    #else
    static PyInterpreterState *main_interpreter = NULL;
    PyInterpreterState *current_interpreter = PyThreadState_Get()->interp;
    if (!main_interpreter) {
        main_interpreter = current_interpreter;
    } else if (unlikely(main_interpreter != current_interpreter))
    #endif
    {
        PyErr_SetString(
            PyExc_ImportError,
            "Interpreter change detected - this module can only be loaded into one interpreter per process.");
        return -1;
    }
    return 0;
}
static CYTHON_SMALL_CODE int __Pyx_copy_spec_to_module(PyObject *spec, PyObject *moddict, const char* from_name, const char* to_name, int allow_none) {
    PyObject *value = PyObject_GetAttrString(spec, from_name);
    int result = 0;
    if (likely(value)) {
        if (allow_none || value != Py_None) {
            result = PyDict_SetItemString(moddict, to_name, value);
        }
        Py_DECREF(value);
    } else if (PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Clear();
    } else {
        result = -1;
    }
    return result;
}
static CYTHON_SMALL_CODE PyObject* __pyx_pymod_create(PyObject *spec, CYTHON_UNUSED PyModuleDef *def) {
    PyObject *module = NULL, *moddict, *modname;
    if (__Pyx_check_single_interpreter())
        return NULL;
    if (__pyx_m)
        return __Pyx_NewRef(__pyx_m);
    modname = PyObject_GetAttrString(spec, "name");
    if (unlikely(!modname)) goto bad;
    module = PyModule_NewObject(modname);
    Py_DECREF(modname);
    if (unlikely(!module)) goto bad;
    moddict = PyModule_GetDict(module);
    if (unlikely(!moddict)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "loader", "__loader__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "origin", "__file__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "parent", "__package__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "submodule_search_locations", "__path__", 0) < 0)) goto bad;
    return module;
bad:
    Py_XDECREF(module);
    return NULL;
}


static CYTHON_SMALL_CODE int __pyx_pymod_exec_menu(PyObject *__pyx_pyinit_module)
#endif
#endif
{
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  Py_ssize_t __pyx_t_3;
  Py_UCS4 __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  int __pyx_t_13;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  Py_ssize_t __pyx_t_16;
  PyObject *(*__pyx_t_17)(PyObject *);
  int __pyx_t_18;
  int __pyx_t_19;
  PyObject *__pyx_t_20 = NULL;
  int __pyx_t_21;
  int __pyx_t_22;
  char const *__pyx_t_23;
  PyObject *__pyx_t_24 = NULL;
  PyObject *__pyx_t_25 = NULL;
  PyObject *__pyx_t_26 = NULL;
  PyObject *__pyx_t_27 = NULL;
  PyObject *__pyx_t_28 = NULL;
  PyObject *__pyx_t_29 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  if (__pyx_m) {
    if (__pyx_m == __pyx_pyinit_module) return 0;
    PyErr_SetString(PyExc_RuntimeError, "Module 'menu' has already been imported. Re-initialisation is not supported.");
    return -1;
  }
  #elif PY_MAJOR_VERSION >= 3
  if (__pyx_m) return __Pyx_NewRef(__pyx_m);
  #endif
  #if CYTHON_REFNANNY
__Pyx_RefNanny = __Pyx_RefNannyImportAPI("refnanny");
if (!__Pyx_RefNanny) {
  PyErr_Clear();
  __Pyx_RefNanny = __Pyx_RefNannyImportAPI("Cython.Runtime.refnanny");
  if (!__Pyx_RefNanny)
      Py_FatalError("failed to import 'refnanny' module");
}
#endif
  __Pyx_RefNannySetupContext("__Pyx_PyMODINIT_FUNC PyInit_menu(void)", 0);
  if (__Pyx_check_binary_version() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pxy_PyFrame_Initialize_Offsets
  __Pxy_PyFrame_Initialize_Offsets();
  #endif
  __pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_empty_tuple)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_bytes = PyBytes_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_bytes)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_unicode = PyUnicode_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_unicode)) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pyx_CyFunction_USED
  if (__pyx_CyFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_FusedFunction_USED
  if (__pyx_FusedFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Coroutine_USED
  if (__pyx_Coroutine_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Generator_USED
  if (__pyx_Generator_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_AsyncGen_USED
  if (__pyx_AsyncGen_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_StopAsyncIteration_USED
  if (__pyx_StopAsyncIteration_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  
  
  #if defined(WITH_THREAD) && PY_VERSION_HEX < 0x030700F0 && defined(__PYX_FORCE_INIT_THREADS) && __PYX_FORCE_INIT_THREADS
  PyEval_InitThreads();
  #endif
  
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  __pyx_m = __pyx_pyinit_module;
  Py_INCREF(__pyx_m);
  #else
  #if PY_MAJOR_VERSION < 3
  __pyx_m = Py_InitModule4("menu", __pyx_methods, 0, 0, PYTHON_API_VERSION); Py_XINCREF(__pyx_m);
  #else
  __pyx_m = PyModule_Create(&__pyx_moduledef);
  #endif
  if (unlikely(!__pyx_m)) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  __pyx_d = PyModule_GetDict(__pyx_m); if (unlikely(!__pyx_d)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_d);
  __pyx_b = PyImport_AddModule(__Pyx_BUILTIN_MODULE_NAME); if (unlikely(!__pyx_b)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_b);
  __pyx_cython_runtime = PyImport_AddModule((char *) "cython_runtime"); if (unlikely(!__pyx_cython_runtime)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_cython_runtime);
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  
  if (__Pyx_InitGlobals() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #if PY_MAJOR_VERSION < 3 && (__PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT)
  if (__Pyx_init_sys_getdefaultencoding_params() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  if (__pyx_module_is_main_menu) {
    if (PyObject_SetAttr(__pyx_m, __pyx_n_s_name, __pyx_n_s_main) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  }
  #if PY_MAJOR_VERSION >= 3
  {
    PyObject *modules = PyImport_GetModuleDict(); if (unlikely(!modules)) __PYX_ERR(0, 1, __pyx_L1_error)
    if (!PyDict_GetItemString(modules, "menu")) {
      if (unlikely(PyDict_SetItemString(modules, "menu", __pyx_m) < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
    }
  }
  #endif
  
  if (__Pyx_InitCachedBuiltins() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  
  if (__Pyx_InitCachedConstants() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  
  (void)__Pyx_modinit_global_init_code();
  (void)__Pyx_modinit_variable_export_code();
  (void)__Pyx_modinit_function_export_code();
  if (unlikely(__Pyx_modinit_type_init_code() < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
  (void)__Pyx_modinit_type_import_code();
  (void)__Pyx_modinit_variable_import_code();
  (void)__Pyx_modinit_function_import_code();
  
  #if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
  if (__Pyx_patch_abc() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Author, __pyx_kp_s_Babas_XD) < 0) __PYX_ERR(0, 2, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Github, __pyx_kp_s_github_com_RozhBasXYZ) < 0) __PYX_ERR(0, 3, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Facebook, __pyx_kp_s_facebook_com_ROZHBASXY) < 0) __PYX_ERR(0, 4, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Script, __pyx_kp_s_Blade_Premium_Facebook_Crack) < 0) __PYX_ERR(0, 5, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Create, __pyx_kp_s_01_Oktober_2021) < 0) __PYX_ERR(0, 6, __pyx_L1_error)

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_requests, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_requests, __pyx_t_1) < 0) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_re, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_re, __pyx_t_1) < 0) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_bs4, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_bs4, __pyx_t_1) < 0) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_random, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_random, __pyx_t_1) < 0) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_subprocess, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_subprocess, __pyx_t_1) < 0) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_base64, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_base64, __pyx_t_1) < 0) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_os, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_os, __pyx_t_1) < 0) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_string, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_string, __pyx_t_1) < 0) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_requests); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_Session); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ses, __pyx_t_1) < 0) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_bs4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_BeautifulSoup); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_parser, __pyx_t_2) < 0) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_random); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_randint); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_rr, __pyx_t_1) < 0) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_random); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_choice); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_rc, __pyx_t_2) < 0) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_list_ua, __pyx_t_2) < 0) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_P, __pyx_kp_s_1_97m) < 0) __PYX_ERR(0, 19, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_M, __pyx_kp_s_1_91m) < 0) __PYX_ERR(0, 20, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_H, __pyx_kp_s_1_92m) < 0) __PYX_ERR(0, 21, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_K, __pyx_kp_s_1_93m) < 0) __PYX_ERR(0, 22, __pyx_L1_error)

  
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_4menu_1heker_asu, 0, __pyx_n_s_heker_asu, NULL, __pyx_n_s_menu, __pyx_d, ((PyObject *)__pyx_codeobj__27)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 25, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_heker_asu, __pyx_t_2) < 0) __PYX_ERR(0, 25, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_4menu_3heker_baik, 0, __pyx_n_s_heker_baik, NULL, __pyx_n_s_menu, __pyx_d, ((PyObject *)__pyx_codeobj__29)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 28, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_heker_baik, __pyx_t_2) < 0) __PYX_ERR(0, 28, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyTuple_New(5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = 0;
  __pyx_t_4 = 127;
  __Pyx_INCREF(__pyx_kp_u__30);
  __pyx_t_3 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__30);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_kp_u__30);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_H); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = __Pyx_PyObject_FormatSimple(__pyx_t_1, __pyx_empty_unicode); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_4 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_5) > __pyx_t_4) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_5) : __pyx_t_4;
  __pyx_t_3 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_5);
  __pyx_t_5 = 0;
  __Pyx_INCREF(__pyx_kp_u__31);
  __pyx_t_3 += 1;
  __Pyx_GIVEREF(__pyx_kp_u__31);
  PyTuple_SET_ITEM(__pyx_t_2, 2, __pyx_kp_u__31);
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_P); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_t_5, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_4 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) > __pyx_t_4) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) : __pyx_t_4;
  __pyx_t_3 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 3, __pyx_t_1);
  __pyx_t_1 = 0;
  __Pyx_INCREF(__pyx_kp_u_sedang_mengambil_data_useragent);
  __pyx_t_3 += 36;
  __Pyx_GIVEREF(__pyx_kp_u_sedang_mengambil_data_useragent);
  PyTuple_SET_ITEM(__pyx_t_2, 4, __pyx_kp_u_sedang_mengambil_data_useragent);
  __pyx_t_1 = __Pyx_PyUnicode_Join(__pyx_t_2, 5, __pyx_t_3, __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_6, &__pyx_t_7, &__pyx_t_8);
    __Pyx_XGOTREF(__pyx_t_6);
    __Pyx_XGOTREF(__pyx_t_7);
    __Pyx_XGOTREF(__pyx_t_8);
     {
      __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_ses); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 33, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_get); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 33, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_heker_asu); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 33, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__32, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 33, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 33, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_json); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 33, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_t_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 33, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_data_ua, __pyx_t_2) < 0) __PYX_ERR(0, 33, __pyx_L2_error)
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    }
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    goto __pyx_L7_try_end;
    __pyx_L2_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;

    
     {
      __Pyx_AddTraceback("menu", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_5, &__pyx_t_1) < 0) __PYX_ERR(0, 34, __pyx_L4_except_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_9 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 34, __pyx_L4_except_error)
      __Pyx_GOTREF(__pyx_t_9);
      if (PyDict_SetItem(__pyx_t_9, __pyx_n_s_rozh, __pyx_n_s_Xiaomi) < 0) __PYX_ERR(0, 34, __pyx_L4_except_error)
      if (PyDict_SetItem(__pyx_t_9, __pyx_n_s_bas, __pyx_n_s_xiaomi) < 0) __PYX_ERR(0, 34, __pyx_L4_except_error)
      if (PyDict_SetItem(__pyx_t_9, __pyx_n_s_xyz, __pyx_kp_s_Redmi_Go_Redmi_Note_7_Pro_Redmi) < 0) __PYX_ERR(0, 34, __pyx_L4_except_error)
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_data_ua, __pyx_t_9) < 0) __PYX_ERR(0, 34, __pyx_L4_except_error)
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      goto __pyx_L3_exception_handled;
    }
    __pyx_L4_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_XGIVEREF(__pyx_t_7);
    __Pyx_XGIVEREF(__pyx_t_8);
    __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_7, __pyx_t_8);
    goto __pyx_L1_error;
    __pyx_L3_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_XGIVEREF(__pyx_t_7);
    __Pyx_XGIVEREF(__pyx_t_8);
    __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_7, __pyx_t_8);
    __pyx_L7_try_end:;
  }

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_8, &__pyx_t_7, &__pyx_t_6);
    __Pyx_XGOTREF(__pyx_t_8);
    __Pyx_XGOTREF(__pyx_t_7);
    __Pyx_XGOTREF(__pyx_t_6);
     {
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_ses); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_get); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_heker_asu); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__33, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
      __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_9 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_9);
      if (PyDict_SetItem(__pyx_t_9, __pyx_kp_s_user_agent, __pyx_kp_s_Mozilla_5_0_Linux_Android_10_K_A_2) < 0) __PYX_ERR(0, 36, __pyx_L10_error)
      if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_headers, __pyx_t_9) < 0) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_9, __pyx_n_s_json); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = __Pyx_PyObject_CallNoArg(__pyx_t_2); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_t_9, __pyx_n_s_data); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = __Pyx_GetItemInt(__pyx_t_2, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyObject_Dict_GetItem(__pyx_t_9, __pyx_n_s_version); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_versi_chrome, __pyx_t_2) < 0) __PYX_ERR(0, 36, __pyx_L10_error)
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    }
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    goto __pyx_L15_try_end;
    __pyx_L10_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;

    
     {
      __Pyx_AddTraceback("menu", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_9, &__pyx_t_1) < 0) __PYX_ERR(0, 37, __pyx_L12_except_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_GOTREF(__pyx_t_1);
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_versi_chrome, __pyx_kp_s_122_0_0_0) < 0) __PYX_ERR(0, 37, __pyx_L12_except_error)
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      goto __pyx_L11_exception_handled;
    }
    __pyx_L12_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_8);
    __Pyx_XGIVEREF(__pyx_t_7);
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_ExceptionReset(__pyx_t_8, __pyx_t_7, __pyx_t_6);
    goto __pyx_L1_error;
    __pyx_L11_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_8);
    __Pyx_XGIVEREF(__pyx_t_7);
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_ExceptionReset(__pyx_t_8, __pyx_t_7, __pyx_t_6);
    __pyx_L15_try_end:;
  }

  
  __pyx_t_1 = __pyx_tuple__34; __Pyx_INCREF(__pyx_t_1); __pyx_t_3 = 0;
  for (;;) {
    if (__pyx_t_3 >= 9) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_9 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_3); __Pyx_INCREF(__pyx_t_9); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 39, __pyx_L1_error)
    #else
    __pyx_t_9 = PySequence_ITEM(__pyx_t_1, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 39, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    #endif
    if (PyDict_SetItem(__pyx_d, __pyx_n_s_blade_team, __pyx_t_9) < 0) __PYX_ERR(0, 39, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

    
    {
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __Pyx_ExceptionSave(&__pyx_t_6, &__pyx_t_7, &__pyx_t_8);
      __Pyx_XGOTREF(__pyx_t_6);
      __Pyx_XGOTREF(__pyx_t_7);
      __Pyx_XGOTREF(__pyx_t_8);
       {

        
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_parser); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 41, __pyx_L20_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_ses); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 41, __pyx_L20_error)
        __Pyx_GOTREF(__pyx_t_10);
        __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_t_10, __pyx_n_s_get); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 41, __pyx_L20_error)
        __Pyx_GOTREF(__pyx_t_11);
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_blade_team); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 41, __pyx_L20_error)
        __Pyx_GOTREF(__pyx_t_10);
        __pyx_t_12 = PyNumber_Add(__pyx_kp_s_https_whatmyuseragent_com_brand, __pyx_t_10); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 41, __pyx_L20_error)
        __Pyx_GOTREF(__pyx_t_12);
        __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        __pyx_t_10 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_11))) {
          __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_11);
          if (likely(__pyx_t_10)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_11);
            __Pyx_INCREF(__pyx_t_10);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_11, function);
          }
        }
        __pyx_t_5 = (__pyx_t_10) ? __Pyx_PyObject_Call2Args(__pyx_t_11, __pyx_t_10, __pyx_t_12) : __Pyx_PyObject_CallOneArg(__pyx_t_11, __pyx_t_12);
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
        if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 41, __pyx_L20_error)
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
        __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_text); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 41, __pyx_L20_error)
        __Pyx_GOTREF(__pyx_t_11);
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        __pyx_t_5 = NULL;
        __pyx_t_13 = 0;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_5)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_5);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
            __pyx_t_13 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_2)) {
          PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_t_11, __pyx_kp_s_html_parser};
          __pyx_t_9 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 41, __pyx_L20_error)
          __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
          __Pyx_GOTREF(__pyx_t_9);
          __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
          PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_t_11, __pyx_kp_s_html_parser};
          __pyx_t_9 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 41, __pyx_L20_error)
          __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
          __Pyx_GOTREF(__pyx_t_9);
          __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
        } else
        #endif
        {
          __pyx_t_12 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 41, __pyx_L20_error)
          __Pyx_GOTREF(__pyx_t_12);
          if (__pyx_t_5) {
            __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_12, 0, __pyx_t_5); __pyx_t_5 = NULL;
          }
          __Pyx_GIVEREF(__pyx_t_11);
          PyTuple_SET_ITEM(__pyx_t_12, 0+__pyx_t_13, __pyx_t_11);
          __Pyx_INCREF(__pyx_kp_s_html_parser);
          __Pyx_GIVEREF(__pyx_kp_s_html_parser);
          PyTuple_SET_ITEM(__pyx_t_12, 1+__pyx_t_13, __pyx_kp_s_html_parser);
          __pyx_t_11 = 0;
          __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_12, NULL); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 41, __pyx_L20_error)
          __Pyx_GOTREF(__pyx_t_9);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
        }
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        if (PyDict_SetItem(__pyx_d, __pyx_n_s_link, __pyx_t_9) < 0) __PYX_ERR(0, 41, __pyx_L20_error)
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

        
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_list_ua); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 42, __pyx_L20_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_extend); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 42, __pyx_L20_error)
        __Pyx_GOTREF(__pyx_t_12);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        { 
          __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 42, __pyx_L30_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_link); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 42, __pyx_L30_error)
          __Pyx_GOTREF(__pyx_t_5);
          __pyx_t_10 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_find_all); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 42, __pyx_L30_error)
          __Pyx_GOTREF(__pyx_t_10);
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
          __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 42, __pyx_L30_error)
          __Pyx_GOTREF(__pyx_t_5);
          if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_class, __pyx_n_s_useragent) < 0) __PYX_ERR(0, 42, __pyx_L30_error)
          __pyx_t_14 = NULL;
          __pyx_t_13 = 0;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_10))) {
            __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_10);
            if (likely(__pyx_t_14)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_10);
              __Pyx_INCREF(__pyx_t_14);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_10, function);
              __pyx_t_13 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_10)) {
            PyObject *__pyx_temp[3] = {__pyx_t_14, __pyx_n_s_td, __pyx_t_5};
            __pyx_t_11 = __Pyx_PyFunction_FastCall(__pyx_t_10, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 42, __pyx_L30_error)
            __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
            __Pyx_GOTREF(__pyx_t_11);
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_10)) {
            PyObject *__pyx_temp[3] = {__pyx_t_14, __pyx_n_s_td, __pyx_t_5};
            __pyx_t_11 = __Pyx_PyCFunction_FastCall(__pyx_t_10, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 42, __pyx_L30_error)
            __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
            __Pyx_GOTREF(__pyx_t_11);
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
          } else
          #endif
          {
            __pyx_t_15 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 42, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_15);
            if (__pyx_t_14) {
              __Pyx_GIVEREF(__pyx_t_14); PyTuple_SET_ITEM(__pyx_t_15, 0, __pyx_t_14); __pyx_t_14 = NULL;
            }
            __Pyx_INCREF(__pyx_n_s_td);
            __Pyx_GIVEREF(__pyx_n_s_td);
            PyTuple_SET_ITEM(__pyx_t_15, 0+__pyx_t_13, __pyx_n_s_td);
            __Pyx_GIVEREF(__pyx_t_5);
            PyTuple_SET_ITEM(__pyx_t_15, 1+__pyx_t_13, __pyx_t_5);
            __pyx_t_5 = 0;
            __pyx_t_11 = __Pyx_PyObject_Call(__pyx_t_10, __pyx_t_15, NULL); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 42, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_11);
            __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
          }
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
          if (likely(PyList_CheckExact(__pyx_t_11)) || PyTuple_CheckExact(__pyx_t_11)) {
            __pyx_t_10 = __pyx_t_11; __Pyx_INCREF(__pyx_t_10); __pyx_t_16 = 0;
            __pyx_t_17 = NULL;
          } else {
            __pyx_t_16 = -1; __pyx_t_10 = PyObject_GetIter(__pyx_t_11); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 42, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_10);
            __pyx_t_17 = Py_TYPE(__pyx_t_10)->tp_iternext; if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 42, __pyx_L30_error)
          }
          __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
          for (;;) {
            if (likely(!__pyx_t_17)) {
              if (likely(PyList_CheckExact(__pyx_t_10))) {
                if (__pyx_t_16 >= PyList_GET_SIZE(__pyx_t_10)) break;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                __pyx_t_11 = PyList_GET_ITEM(__pyx_t_10, __pyx_t_16); __Pyx_INCREF(__pyx_t_11); __pyx_t_16++; if (unlikely(0 < 0)) __PYX_ERR(0, 42, __pyx_L30_error)
                #else
                __pyx_t_11 = PySequence_ITEM(__pyx_t_10, __pyx_t_16); __pyx_t_16++; if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 42, __pyx_L30_error)
                __Pyx_GOTREF(__pyx_t_11);
                #endif
              } else {
                if (__pyx_t_16 >= PyTuple_GET_SIZE(__pyx_t_10)) break;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                __pyx_t_11 = PyTuple_GET_ITEM(__pyx_t_10, __pyx_t_16); __Pyx_INCREF(__pyx_t_11); __pyx_t_16++; if (unlikely(0 < 0)) __PYX_ERR(0, 42, __pyx_L30_error)
                #else
                __pyx_t_11 = PySequence_ITEM(__pyx_t_10, __pyx_t_16); __pyx_t_16++; if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 42, __pyx_L30_error)
                __Pyx_GOTREF(__pyx_t_11);
                #endif
              }
            } else {
              __pyx_t_11 = __pyx_t_17(__pyx_t_10);
              if (unlikely(!__pyx_t_11)) {
                PyObject* exc_type = PyErr_Occurred();
                if (exc_type) {
                  if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
                  else __PYX_ERR(0, 42, __pyx_L30_error)
                }
                break;
              }
              __Pyx_GOTREF(__pyx_t_11);
            }
            __Pyx_XGOTREF(__pyx_7genexpr__pyx_v_4menu_z);
            __Pyx_DECREF_SET(__pyx_7genexpr__pyx_v_4menu_z, __pyx_t_11);
            __Pyx_GIVEREF(__pyx_t_11);
            __pyx_t_11 = 0;
            __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_7genexpr__pyx_v_4menu_z, __pyx_n_s_text); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 42, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_11);
            __pyx_t_18 = (__Pyx_PySequence_ContainsTF(__pyx_n_s_Build, __pyx_t_11, Py_EQ)); if (unlikely(__pyx_t_18 < 0)) __PYX_ERR(0, 42, __pyx_L30_error)
            __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
            __pyx_t_19 = (__pyx_t_18 != 0);
            if (__pyx_t_19) {
              __Pyx_GetModuleGlobalName(__pyx_t_15, __pyx_n_s_re); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 42, __pyx_L30_error)
              __Pyx_GOTREF(__pyx_t_15);
              __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_15, __pyx_n_s_findall); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 42, __pyx_L30_error)
              __Pyx_GOTREF(__pyx_t_5);
              __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
              __pyx_t_15 = __Pyx_PyObject_GetAttrStr(__pyx_7genexpr__pyx_v_4menu_z, __pyx_n_s_text); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 42, __pyx_L30_error)
              __Pyx_GOTREF(__pyx_t_15);
              __pyx_t_14 = NULL;
              __pyx_t_13 = 0;
              if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
                __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_5);
                if (likely(__pyx_t_14)) {
                  PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
                  __Pyx_INCREF(__pyx_t_14);
                  __Pyx_INCREF(function);
                  __Pyx_DECREF_SET(__pyx_t_5, function);
                  __pyx_t_13 = 1;
                }
              }
              #if CYTHON_FAST_PYCALL
              if (PyFunction_Check(__pyx_t_5)) {
                PyObject *__pyx_temp[3] = {__pyx_t_14, __pyx_kp_s_Android_Build, __pyx_t_15};
                __pyx_t_11 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 42, __pyx_L30_error)
                __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
                __Pyx_GOTREF(__pyx_t_11);
                __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
              } else
              #endif
              #if CYTHON_FAST_PYCCALL
              if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
                PyObject *__pyx_temp[3] = {__pyx_t_14, __pyx_kp_s_Android_Build, __pyx_t_15};
                __pyx_t_11 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 42, __pyx_L30_error)
                __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
                __Pyx_GOTREF(__pyx_t_11);
                __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
              } else
              #endif
              {
                __pyx_t_20 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_20)) __PYX_ERR(0, 42, __pyx_L30_error)
                __Pyx_GOTREF(__pyx_t_20);
                if (__pyx_t_14) {
                  __Pyx_GIVEREF(__pyx_t_14); PyTuple_SET_ITEM(__pyx_t_20, 0, __pyx_t_14); __pyx_t_14 = NULL;
                }
                __Pyx_INCREF(__pyx_kp_s_Android_Build);
                __Pyx_GIVEREF(__pyx_kp_s_Android_Build);
                PyTuple_SET_ITEM(__pyx_t_20, 0+__pyx_t_13, __pyx_kp_s_Android_Build);
                __Pyx_GIVEREF(__pyx_t_15);
                PyTuple_SET_ITEM(__pyx_t_20, 1+__pyx_t_13, __pyx_t_15);
                __pyx_t_15 = 0;
                __pyx_t_11 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_20, NULL); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 42, __pyx_L30_error)
                __Pyx_GOTREF(__pyx_t_11);
                __Pyx_DECREF(__pyx_t_20); __pyx_t_20 = 0;
              }
              __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
              __pyx_t_5 = __Pyx_GetItemInt(__pyx_t_11, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 42, __pyx_L30_error)
              __Pyx_GOTREF(__pyx_t_5);
              __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
              if (unlikely(__Pyx_ListComp_Append(__pyx_t_2, (PyObject*)__pyx_t_5))) __PYX_ERR(0, 42, __pyx_L30_error)
              __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            }
          }
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
          __Pyx_GOTREF(__pyx_7genexpr__pyx_v_4menu_z);
          __Pyx_DECREF_SET(__pyx_7genexpr__pyx_v_4menu_z, Py_None);
          goto __pyx_L34_exit_scope;
          __pyx_L30_error:;
          __Pyx_GOTREF(__pyx_7genexpr__pyx_v_4menu_z);
          __Pyx_DECREF_SET(__pyx_7genexpr__pyx_v_4menu_z, Py_None);
          goto __pyx_L20_error;
          __pyx_L34_exit_scope:;
        } 
        __pyx_t_10 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_12))) {
          __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_12);
          if (likely(__pyx_t_10)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
            __Pyx_INCREF(__pyx_t_10);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_12, function);
          }
        }
        __pyx_t_9 = (__pyx_t_10) ? __Pyx_PyObject_Call2Args(__pyx_t_12, __pyx_t_10, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_12, __pyx_t_2);
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 42, __pyx_L20_error)
        __Pyx_GOTREF(__pyx_t_9);
        __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

        
      }
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
      goto __pyx_L27_try_end;
      __pyx_L20_error:;
      __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
      __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
      __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_20); __pyx_t_20 = 0;
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;

      
      __pyx_t_13 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
      if (__pyx_t_13) {
        __Pyx_AddTraceback("menu", __pyx_clineno, __pyx_lineno, __pyx_filename);
        if (__Pyx_GetException(&__pyx_t_9, &__pyx_t_12, &__pyx_t_2) < 0) __PYX_ERR(0, 43, __pyx_L22_except_error)
        __Pyx_GOTREF(__pyx_t_9);
        __Pyx_GOTREF(__pyx_t_12);
        __Pyx_GOTREF(__pyx_t_2);
        if (PyDict_SetItem(__pyx_d, __pyx_n_s_e, __pyx_t_12) < 0) __PYX_ERR(0, 43, __pyx_L22_except_error)
         {

          
          __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_list_ua); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 44, __pyx_L40_error)
          __Pyx_GOTREF(__pyx_t_10);
          __pyx_t_21 = __Pyx_PyObject_Append(__pyx_t_10, __pyx_kp_s_Redmi_Note_10_Pro); if (unlikely(__pyx_t_21 == ((int)-1))) __PYX_ERR(0, 44, __pyx_L40_error)
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        }

        
         {
          {
            if (unlikely(__Pyx_PyObject_DelAttrStr(__pyx_m, __pyx_n_s_e) < 0)) { if (likely(PyErr_ExceptionMatches(PyExc_AttributeError))) PyErr_Clear(); else __PYX_ERR(0, 43, __pyx_L22_except_error) }
            goto __pyx_L41;
          }
          __pyx_L40_error:;
          {
            __Pyx_PyThreadState_declare
            __Pyx_PyThreadState_assign
            __pyx_t_24 = 0; __pyx_t_25 = 0; __pyx_t_26 = 0; __pyx_t_27 = 0; __pyx_t_28 = 0; __pyx_t_29 = 0;
            __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
            __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
            __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
            __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
            __Pyx_XDECREF(__pyx_t_20); __pyx_t_20 = 0;
            __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
            if (PY_MAJOR_VERSION >= 3) __Pyx_ExceptionSwap(&__pyx_t_27, &__pyx_t_28, &__pyx_t_29);
            if ((PY_MAJOR_VERSION < 3) || unlikely(__Pyx_GetException(&__pyx_t_24, &__pyx_t_25, &__pyx_t_26) < 0)) __Pyx_ErrFetch(&__pyx_t_24, &__pyx_t_25, &__pyx_t_26);
            __Pyx_XGOTREF(__pyx_t_24);
            __Pyx_XGOTREF(__pyx_t_25);
            __Pyx_XGOTREF(__pyx_t_26);
            __Pyx_XGOTREF(__pyx_t_27);
            __Pyx_XGOTREF(__pyx_t_28);
            __Pyx_XGOTREF(__pyx_t_29);
            __pyx_t_13 = __pyx_lineno; __pyx_t_22 = __pyx_clineno; __pyx_t_23 = __pyx_filename;
            {
              if (unlikely(__Pyx_PyObject_DelAttrStr(__pyx_m, __pyx_n_s_e) < 0)) { if (likely(PyErr_ExceptionMatches(PyExc_AttributeError))) PyErr_Clear(); else __PYX_ERR(0, 43, __pyx_L45_error) }
            }
            if (PY_MAJOR_VERSION >= 3) {
              __Pyx_XGIVEREF(__pyx_t_27);
              __Pyx_XGIVEREF(__pyx_t_28);
              __Pyx_XGIVEREF(__pyx_t_29);
              __Pyx_ExceptionReset(__pyx_t_27, __pyx_t_28, __pyx_t_29);
            }
            __Pyx_XGIVEREF(__pyx_t_24);
            __Pyx_XGIVEREF(__pyx_t_25);
            __Pyx_XGIVEREF(__pyx_t_26);
            __Pyx_ErrRestore(__pyx_t_24, __pyx_t_25, __pyx_t_26);
            __pyx_t_24 = 0; __pyx_t_25 = 0; __pyx_t_26 = 0; __pyx_t_27 = 0; __pyx_t_28 = 0; __pyx_t_29 = 0;
            __pyx_lineno = __pyx_t_13; __pyx_clineno = __pyx_t_22; __pyx_filename = __pyx_t_23;
            goto __pyx_L22_except_error;
            __pyx_L45_error:;
            if (PY_MAJOR_VERSION >= 3) {
              __Pyx_XGIVEREF(__pyx_t_27);
              __Pyx_XGIVEREF(__pyx_t_28);
              __Pyx_XGIVEREF(__pyx_t_29);
              __Pyx_ExceptionReset(__pyx_t_27, __pyx_t_28, __pyx_t_29);
            }
            __Pyx_XDECREF(__pyx_t_24); __pyx_t_24 = 0;
            __Pyx_XDECREF(__pyx_t_25); __pyx_t_25 = 0;
            __Pyx_XDECREF(__pyx_t_26); __pyx_t_26 = 0;
            __pyx_t_27 = 0; __pyx_t_28 = 0; __pyx_t_29 = 0;
            goto __pyx_L22_except_error;
          }
          __pyx_L41:;
        }
        __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
        __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        goto __pyx_L21_exception_handled;
      }
      goto __pyx_L22_except_error;
      __pyx_L22_except_error:;

      
      __Pyx_XGIVEREF(__pyx_t_6);
      __Pyx_XGIVEREF(__pyx_t_7);
      __Pyx_XGIVEREF(__pyx_t_8);
      __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_7, __pyx_t_8);
      goto __pyx_L1_error;
      __pyx_L21_exception_handled:;
      __Pyx_XGIVEREF(__pyx_t_6);
      __Pyx_XGIVEREF(__pyx_t_7);
      __Pyx_XGIVEREF(__pyx_t_8);
      __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_7, __pyx_t_8);
      __pyx_L27_try_end:;
    }

    
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_4menu_5ua_biasa, 0, __pyx_n_s_ua_biasa, NULL, __pyx_n_s_menu, __pyx_d, ((PyObject *)__pyx_codeobj__36)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ua_biasa, __pyx_t_1) < 0) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_4menu_7ua_api, 0, __pyx_n_s_ua_api, NULL, __pyx_n_s_menu, __pyx_d, ((PyObject *)__pyx_codeobj__38)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ua_api, __pyx_t_1) < 0) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_4menu_9api_ios, 0, __pyx_n_s_api_ios, NULL, __pyx_n_s_menu, __pyx_d, ((PyObject *)__pyx_codeobj__40)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_api_ios, __pyx_t_1) < 0) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_4menu_11ua_web, 0, __pyx_n_s_ua_web, NULL, __pyx_n_s_menu, __pyx_d, ((PyObject *)__pyx_codeobj__41)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ua_web, __pyx_t_1) < 0) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_test, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  

  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_XDECREF(__pyx_t_15);
  __Pyx_XDECREF(__pyx_t_20);
  if (__pyx_m) {
    if (__pyx_d) {
      __Pyx_AddTraceback("init menu", __pyx_clineno, __pyx_lineno, __pyx_filename);
    }
    Py_CLEAR(__pyx_m);
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init menu");
  }
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  return (__pyx_m != NULL) ? 0 : -1;
  #elif PY_MAJOR_VERSION >= 3
  return __pyx_m;
  #else
  return;
  #endif
}



#if CYTHON_REFNANNY
static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname) {
    PyObject *m = NULL, *p = NULL;
    void *r = NULL;
    m = PyImport_ImportModule(modname);
    if (!m) goto end;
    p = PyObject_GetAttrString(m, "RefNannyAPI");
    if (!p) goto end;
    r = PyLong_AsVoidPtr(p);
end:
    Py_XDECREF(p);
    Py_XDECREF(m);
    return (__Pyx_RefNannyAPIStruct *)r;
}
#endif


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_getattro))
        return tp->tp_getattro(obj, attr_name);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_getattr))
        return tp->tp_getattr(obj, PyString_AS_STRING(attr_name));
#endif
    return PyObject_GetAttr(obj, attr_name);
}
#endif


static PyObject *__Pyx_GetBuiltinName(PyObject *name) {
    PyObject* result = __Pyx_PyObject_GetAttrStr(__pyx_b, name);
    if (unlikely(!result)) {
        PyErr_Format(PyExc_NameError,
#if PY_MAJOR_VERSION >= 3
            "name '%U' is not defined", name);
#else
            "name '%.200s' is not defined", PyString_AS_STRING(name));
#endif
    }
    return result;
}


#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    return likely(dict) ? __PYX_GET_DICT_VERSION(dict) : 0;
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj) {
    PyObject **dictptr = NULL;
    Py_ssize_t offset = Py_TYPE(obj)->tp_dictoffset;
    if (offset) {
#if CYTHON_COMPILING_IN_CPYTHON
        dictptr = (likely(offset > 0)) ? (PyObject **) ((char *)obj + offset) : _PyObject_GetDictPtr(obj);
#else
        dictptr = _PyObject_GetDictPtr(obj);
#endif
    }
    return (dictptr && *dictptr) ? __PYX_GET_DICT_VERSION(*dictptr) : 0;
}
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    if (unlikely(!dict) || unlikely(tp_dict_version != __PYX_GET_DICT_VERSION(dict)))
        return 0;
    return obj_dict_version == __Pyx_get_object_dict_version(obj);
}
#endif


#if CYTHON_USE_DICT_VERSIONS
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value)
#else
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name)
#endif
{
    PyObject *result;
#if !CYTHON_AVOID_BORROWED_REFS
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1
    result = _PyDict_GetItem_KnownHash(__pyx_d, name, ((PyASCIIObject *) name)->hash);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    } else if (unlikely(PyErr_Occurred())) {
        return NULL;
    }
#else
    result = PyDict_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
#endif
#else
    result = PyObject_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
    PyErr_Clear();
#endif
    return __Pyx_GetBuiltinName(name);
}


#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject * __Pyx_PyCFunction_FastCall(PyObject *func_obj, PyObject **args, Py_ssize_t nargs) {
    PyCFunctionObject *func = (PyCFunctionObject*)func_obj;
    PyCFunction meth = PyCFunction_GET_FUNCTION(func);
    PyObject *self = PyCFunction_GET_SELF(func);
    int flags = PyCFunction_GET_FLAGS(func);
    assert(PyCFunction_Check(func));
    assert(METH_FASTCALL == (flags & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)));
    assert(nargs >= 0);
    assert(nargs == 0 || args != NULL);
    /* _PyCFunction_FastCallDict() must not be called with an exception set,
       because it may clear it (directly or indirectly) and so the
       caller loses its exception */
    assert(!PyErr_Occurred());
    if ((PY_VERSION_HEX < 0x030700A0) || unlikely(flags & METH_KEYWORDS)) {
        return (*((__Pyx_PyCFunctionFastWithKeywords)(void*)meth)) (self, args, nargs, NULL);
    } else {
        return (*((__Pyx_PyCFunctionFast)(void*)meth)) (self, args, nargs);
    }
}
#endif


#if CYTHON_FAST_PYCALL
static PyObject* __Pyx_PyFunction_FastCallNoKw(PyCodeObject *co, PyObject **args, Py_ssize_t na,
                                               PyObject *globals) {
    PyFrameObject *f;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject **fastlocals;
    Py_ssize_t i;
    PyObject *result;
    assert(globals != NULL);
    /* XXX Perhaps we should create a specialized
       PyFrame_New() that doesn't take locals, but does
       take builtins without sanity checking them.
       */
    assert(tstate != NULL);
    f = PyFrame_New(tstate, co, globals, NULL);
    if (f == NULL) {
        return NULL;
    }
    fastlocals = __Pyx_PyFrame_GetLocalsplus(f);
    for (i = 0; i < na; i++) {
        Py_INCREF(*args);
        fastlocals[i] = *args++;
    }
    result = PyEval_EvalFrameEx(f,0);
    ++tstate->recursion_depth;
    Py_DECREF(f);
    --tstate->recursion_depth;
    return result;
}
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs) {
    PyCodeObject *co = (PyCodeObject *)PyFunction_GET_CODE(func);
    PyObject *globals = PyFunction_GET_GLOBALS(func);
    PyObject *argdefs = PyFunction_GET_DEFAULTS(func);
    PyObject *closure;
#if PY_MAJOR_VERSION >= 3
    PyObject *kwdefs;
#endif
    PyObject *kwtuple, **k;
    PyObject **d;
    Py_ssize_t nd;
    Py_ssize_t nk;
    PyObject *result;
    assert(kwargs == NULL || PyDict_Check(kwargs));
    nk = kwargs ? PyDict_Size(kwargs) : 0;
    if (Py_EnterRecursiveCall((char*)" while calling a Python object")) {
        return NULL;
    }
    if (
#if PY_MAJOR_VERSION >= 3
            co->co_kwonlyargcount == 0 &&
#endif
            likely(kwargs == NULL || nk == 0) &&
            co->co_flags == (CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE)) {
        if (argdefs == NULL && co->co_argcount == nargs) {
            result = __Pyx_PyFunction_FastCallNoKw(co, args, nargs, globals);
            goto done;
        }
        else if (nargs == 0 && argdefs != NULL
                 && co->co_argcount == Py_SIZE(argdefs)) {
            /* function called with no arguments, but all parameters have
               a default value: use default values as arguments .*/
            args = &PyTuple_GET_ITEM(argdefs, 0);
            result =__Pyx_PyFunction_FastCallNoKw(co, args, Py_SIZE(argdefs), globals);
            goto done;
        }
    }
    if (kwargs != NULL) {
        Py_ssize_t pos, i;
        kwtuple = PyTuple_New(2 * nk);
        if (kwtuple == NULL) {
            result = NULL;
            goto done;
        }
        k = &PyTuple_GET_ITEM(kwtuple, 0);
        pos = i = 0;
        while (PyDict_Next(kwargs, &pos, &k[i], &k[i+1])) {
            Py_INCREF(k[i]);
            Py_INCREF(k[i+1]);
            i += 2;
        }
        nk = i / 2;
    }
    else {
        kwtuple = NULL;
        k = NULL;
    }
    closure = PyFunction_GET_CLOSURE(func);
#if PY_MAJOR_VERSION >= 3
    kwdefs = PyFunction_GET_KW_DEFAULTS(func);
#endif
    if (argdefs != NULL) {
        d = &PyTuple_GET_ITEM(argdefs, 0);
        nd = Py_SIZE(argdefs);
    }
    else {
        d = NULL;
        nd = 0;
    }
#if PY_MAJOR_VERSION >= 3
    result = PyEval_EvalCodeEx((PyObject*)co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, kwdefs, closure);
#else
    result = PyEval_EvalCodeEx(co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, closure);
#endif
    Py_XDECREF(kwtuple);
done:
    Py_LeaveRecursiveCall();
    return result;
}
#endif
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    PyObject *result;
    ternaryfunc call = Py_TYPE(func)->tp_call;
    if (unlikely(!call))
        return PyObject_Call(func, arg, kw);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = (*call)(func, arg, kw);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif


static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2) {
    PyObject *args, *result = NULL;
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyFunction_FastCall(function, args, 2);
    }
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyCFunction_FastCall(function, args, 2);
    }
    #endif
    args = PyTuple_New(2);
    if (unlikely(!args)) goto done;
    Py_INCREF(arg1);
    PyTuple_SET_ITEM(args, 0, arg1);
    Py_INCREF(arg2);
    PyTuple_SET_ITEM(args, 1, arg2);
    Py_INCREF(function);
    result = __Pyx_PyObject_Call(function, args, NULL);
    Py_DECREF(args);
    Py_DECREF(function);
done:
    return result;
}


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg) {
    PyObject *self, *result;
    PyCFunction cfunc;
    cfunc = PyCFunction_GET_FUNCTION(func);
    self = PyCFunction_GET_SELF(func);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = cfunc(self, arg);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static PyObject* __Pyx__PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_New(1);
    if (unlikely(!args)) return NULL;
    Py_INCREF(arg);
    PyTuple_SET_ITEM(args, 0, arg);
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, &arg, 1);
    }
#endif
    if (likely(PyCFunction_Check(func))) {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_O)) {
            return __Pyx_PyObject_CallMethO(func, arg);
#if CYTHON_FAST_PYCCALL
        } else if (__Pyx_PyFastCFunction_Check(func)) {
            return __Pyx_PyCFunction_FastCall(func, &arg, 1);
#endif
        }
    }
    return __Pyx__PyObject_CallOneArg(func, arg);
}
#else
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_Pack(1, arg);
    if (unlikely(!args)) return NULL;
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, NULL, 0);
    }
#endif
#if defined(__Pyx_CyFunction_USED) && defined(NDEBUG)
    if (likely(PyCFunction_Check(func) || __Pyx_CyFunction_Check(func)))
#else
    if (likely(PyCFunction_Check(func)))
#endif
    {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_NOARGS)) {
            return __Pyx_PyObject_CallMethO(func, NULL);
        }
    }
    return __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL);
}
#endif


static PyObject* __Pyx_PyUnicode_Join(PyObject* value_tuple, Py_ssize_t value_count, Py_ssize_t result_ulength,
                                      CYTHON_UNUSED Py_UCS4 max_char) {
#if CYTHON_USE_UNICODE_INTERNALS && CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    PyObject *result_uval;
    int result_ukind;
    Py_ssize_t i, char_pos;
    void *result_udata;
#if CYTHON_PEP393_ENABLED
    result_uval = PyUnicode_New(result_ulength, max_char);
    if (unlikely(!result_uval)) return NULL;
    result_ukind = (max_char <= 255) ? PyUnicode_1BYTE_KIND : (max_char <= 65535) ? PyUnicode_2BYTE_KIND : PyUnicode_4BYTE_KIND;
    result_udata = PyUnicode_DATA(result_uval);
#else
    result_uval = PyUnicode_FromUnicode(NULL, result_ulength);
    if (unlikely(!result_uval)) return NULL;
    result_ukind = sizeof(Py_UNICODE);
    result_udata = PyUnicode_AS_UNICODE(result_uval);
#endif
    char_pos = 0;
    for (i=0; i < value_count; i++) {
        int ukind;
        Py_ssize_t ulength;
        void *udata;
        PyObject *uval = PyTuple_GET_ITEM(value_tuple, i);
        if (unlikely(__Pyx_PyUnicode_READY(uval)))
            goto bad;
        ulength = __Pyx_PyUnicode_GET_LENGTH(uval);
        if (unlikely(!ulength))
            continue;
        if (unlikely(char_pos + ulength < 0))
            goto overflow;
        ukind = __Pyx_PyUnicode_KIND(uval);
        udata = __Pyx_PyUnicode_DATA(uval);
        if (!CYTHON_PEP393_ENABLED || ukind == result_ukind) {
            memcpy((char *)result_udata + char_pos * result_ukind, udata, (size_t) (ulength * result_ukind));
        } else {
            #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030300F0 || defined(_PyUnicode_FastCopyCharacters)
            _PyUnicode_FastCopyCharacters(result_uval, char_pos, uval, 0, ulength);
            #else
            Py_ssize_t j;
            for (j=0; j < ulength; j++) {
                Py_UCS4 uchar = __Pyx_PyUnicode_READ(ukind, udata, j);
                __Pyx_PyUnicode_WRITE(result_ukind, result_udata, char_pos+j, uchar);
            }
            #endif
        }
        char_pos += ulength;
    }
    return result_uval;
overflow:
    PyErr_SetString(PyExc_OverflowError, "join() result is too long for a Python string");
bad:
    Py_DECREF(result_uval);
    return NULL;
#else
    result_ulength++;
    value_count++;
    return PyUnicode_Join(__pyx_empty_unicode, value_tuple);
#endif
}


static CYTHON_INLINE void __Pyx_RaiseClosureNameError(const char *varname) {
    PyErr_Format(PyExc_NameError, "free variable '%s' referenced before assignment in enclosing scope", varname);
}


#if !CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyBytes_Join(PyObject* sep, PyObject* values) {
    return PyObject_CallMethodObjArgs(sep, __pyx_n_s_join, values, NULL);
}
#endif


#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key) {
    PyObject *value;
    value = PyDict_GetItemWithError(d, key);
    if (unlikely(!value)) {
        if (!PyErr_Occurred()) {
            if (unlikely(PyTuple_Check(key))) {
                PyObject* args = PyTuple_Pack(1, key);
                if (likely(args)) {
                    PyErr_SetObject(PyExc_KeyError, args);
                    Py_DECREF(args);
                }
            } else {
                PyErr_SetObject(PyExc_KeyError, key);
            }
        }
        return NULL;
    }
    Py_INCREF(value);
    return value;
}
#endif


static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j) {
    PyObject *r;
    if (!j) return NULL;
    r = PyObject_GetItem(o, j);
    Py_DECREF(j);
    return r;
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyList_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyList_GET_SIZE(o)))) {
        PyObject *r = PyList_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyTuple_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyTuple_GET_SIZE(o)))) {
        PyObject *r = PyTuple_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i, int is_list,
                                                     CYTHON_NCP_UNUSED int wraparound,
                                                     CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS && CYTHON_USE_TYPE_SLOTS
    if (is_list || PyList_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyList_GET_SIZE(o);
        if ((!boundscheck) || (likely(__Pyx_is_valid_index(n, PyList_GET_SIZE(o))))) {
            PyObject *r = PyList_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    }
    else if (PyTuple_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyTuple_GET_SIZE(o);
        if ((!boundscheck) || likely(__Pyx_is_valid_index(n, PyTuple_GET_SIZE(o)))) {
            PyObject *r = PyTuple_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    } else {
        PySequenceMethods *m = Py_TYPE(o)->tp_as_sequence;
        if (likely(m && m->sq_item)) {
            if (wraparound && unlikely(i < 0) && likely(m->sq_length)) {
                Py_ssize_t l = m->sq_length(o);
                if (likely(l >= 0)) {
                    i += l;
                } else {
                    if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                        return NULL;
                    PyErr_Clear();
                }
            }
            return m->sq_item(o, i);
        }
    }
#else
    if (is_list || PySequence_Check(o)) {
        return PySequence_GetItem(o, i);
    }
#endif
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
}


#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static PyObject *__Pyx_RaiseGenericGetAttributeError(PyTypeObject *tp, PyObject *attr_name) {
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, attr_name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(attr_name));
#endif
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name) {
    PyObject *descr;
    PyTypeObject *tp = Py_TYPE(obj);
    if (unlikely(!PyString_Check(attr_name))) {
        return PyObject_GenericGetAttr(obj, attr_name);
    }
    assert(!tp->tp_dictoffset);
    descr = _PyType_Lookup(tp, attr_name);
    if (unlikely(!descr)) {
        return __Pyx_RaiseGenericGetAttributeError(tp, attr_name);
    }
    Py_INCREF(descr);
    #if PY_MAJOR_VERSION < 3
    if (likely(PyType_HasFeature(Py_TYPE(descr), Py_TPFLAGS_HAVE_CLASS)))
    #endif
    {
        descrgetfunc f = Py_TYPE(descr)->tp_descr_get;
        if (unlikely(f)) {
            PyObject *res = f(descr, obj, (PyObject *)tp);
            Py_DECREF(descr);
            return res;
        }
    }
    return descr;
}
#endif


static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level) {
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    #if PY_MAJOR_VERSION < 3
    PyObject *py_import;
    py_import = __Pyx_PyObject_GetAttrStr(__pyx_b, __pyx_n_s_import);
    if (!py_import)
        goto bad;
    #endif
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    {
        #if PY_MAJOR_VERSION >= 3
        if (level == -1) {
            if ((1) && (strchr(__Pyx_MODULE_NAME, '.'))) {
                module = PyImport_ImportModuleLevelObject(
                    name, global_dict, empty_dict, list, 1);
                if (!module) {
                    if (!PyErr_ExceptionMatches(PyExc_ImportError))
                        goto bad;
                    PyErr_Clear();
                }
            }
            level = 0;
        }
        #endif
        if (!module) {
            #if PY_MAJOR_VERSION < 3
            PyObject *py_level = PyInt_FromLong(level);
            if (!py_level)
                goto bad;
            module = PyObject_CallFunctionObjArgs(py_import,
                name, global_dict, empty_dict, list, py_level, (PyObject *)NULL);
            Py_DECREF(py_level);
            #else
            module = PyImport_ImportModuleLevelObject(
                name, global_dict, empty_dict, list, level);
            #endif
        }
    }
bad:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(py_import);
    #endif
    Py_XDECREF(empty_list);
    Py_XDECREF(empty_dict);
    return module;
}


static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type) {
    PyObject* fake_module;
    PyTypeObject* cached_type = NULL;
    fake_module = PyImport_AddModule((char*) "_cython_" CYTHON_ABI);
    if (!fake_module) return NULL;
    Py_INCREF(fake_module);
    cached_type = (PyTypeObject*) PyObject_GetAttrString(fake_module, type->tp_name);
    if (cached_type) {
        if (!PyType_Check((PyObject*)cached_type)) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s is not a type object",
                type->tp_name);
            goto bad;
        }
        if (cached_type->tp_basicsize != type->tp_basicsize) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s has the wrong size, try recompiling",
                type->tp_name);
            goto bad;
        }
    } else {
        if (!PyErr_ExceptionMatches(PyExc_AttributeError)) goto bad;
        PyErr_Clear();
        if (PyType_Ready(type) < 0) goto bad;
        if (PyObject_SetAttrString(fake_module, type->tp_name, (PyObject*) type) < 0)
            goto bad;
        Py_INCREF(type);
        cached_type = type;
    }
done:
    Py_DECREF(fake_module);
    return cached_type;
bad:
    Py_XDECREF(cached_type);
    cached_type = NULL;
    goto done;
}


#include <structmember.h>
static PyObject *
__Pyx_CyFunction_get_doc(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *closure)
{
    if (unlikely(op->func_doc == NULL)) {
        if (op->func.m_ml->ml_doc) {
#if PY_MAJOR_VERSION >= 3
            op->func_doc = PyUnicode_FromString(op->func.m_ml->ml_doc);
#else
            op->func_doc = PyString_FromString(op->func.m_ml->ml_doc);
#endif
            if (unlikely(op->func_doc == NULL))
                return NULL;
        } else {
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    Py_INCREF(op->func_doc);
    return op->func_doc;
}
static int
__Pyx_CyFunction_set_doc(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp = op->func_doc;
    if (value == NULL) {
        value = Py_None;
    }
    Py_INCREF(value);
    op->func_doc = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_name(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_name == NULL)) {
#if PY_MAJOR_VERSION >= 3
        op->func_name = PyUnicode_InternFromString(op->func.m_ml->ml_name);
#else
        op->func_name = PyString_InternFromString(op->func.m_ml->ml_name);
#endif
        if (unlikely(op->func_name == NULL))
            return NULL;
    }
    Py_INCREF(op->func_name);
    return op->func_name;
}
static int
__Pyx_CyFunction_set_name(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    tmp = op->func_name;
    Py_INCREF(value);
    op->func_name = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_qualname(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_qualname);
    return op->func_qualname;
}
static int
__Pyx_CyFunction_set_qualname(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    tmp = op->func_qualname;
    Py_INCREF(value);
    op->func_qualname = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_self(__pyx_CyFunctionObject *m, CYTHON_UNUSED void *closure)
{
    PyObject *self;
    self = m->func_closure;
    if (self == NULL)
        self = Py_None;
    Py_INCREF(self);
    return self;
}
static PyObject *
__Pyx_CyFunction_get_dict(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_dict == NULL)) {
        op->func_dict = PyDict_New();
        if (unlikely(op->func_dict == NULL))
            return NULL;
    }
    Py_INCREF(op->func_dict);
    return op->func_dict;
}
static int
__Pyx_CyFunction_set_dict(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
    if (unlikely(value == NULL)) {
        PyErr_SetString(PyExc_TypeError,
               "function's dictionary may not be deleted");
        return -1;
    }
    if (unlikely(!PyDict_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
               "setting function's dictionary to a non-dict");
        return -1;
    }
    tmp = op->func_dict;
    Py_INCREF(value);
    op->func_dict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_globals(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_globals);
    return op->func_globals;
}
static PyObject *
__Pyx_CyFunction_get_closure(CYTHON_UNUSED __pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(Py_None);
    return Py_None;
}
static PyObject *
__Pyx_CyFunction_get_code(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    PyObject* result = (op->func_code) ? op->func_code : Py_None;
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_init_defaults(__pyx_CyFunctionObject *op) {
    int result = 0;
    PyObject *res = op->defaults_getter((PyObject *) op);
    if (unlikely(!res))
        return -1;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    op->defaults_tuple = PyTuple_GET_ITEM(res, 0);
    Py_INCREF(op->defaults_tuple);
    op->defaults_kwdict = PyTuple_GET_ITEM(res, 1);
    Py_INCREF(op->defaults_kwdict);
    #else
    op->defaults_tuple = PySequence_ITEM(res, 0);
    if (unlikely(!op->defaults_tuple)) result = -1;
    else {
        op->defaults_kwdict = PySequence_ITEM(res, 1);
        if (unlikely(!op->defaults_kwdict)) result = -1;
    }
    #endif
    Py_DECREF(res);
    return result;
}
static int
__Pyx_CyFunction_set_defaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyTuple_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__defaults__ must be set to a tuple object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_tuple;
    op->defaults_tuple = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_defaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_tuple;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_tuple;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_kwdefaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__kwdefaults__ must be set to a dict object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_kwdict;
    op->defaults_kwdict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_kwdefaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_kwdict;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_kwdict;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_annotations(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value || value == Py_None) {
        value = NULL;
    } else if (!PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__annotations__ must be set to a dict object");
        return -1;
    }
    Py_XINCREF(value);
    tmp = op->func_annotations;
    op->func_annotations = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_annotations(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->func_annotations;
    if (unlikely(!result)) {
        result = PyDict_New();
        if (unlikely(!result)) return NULL;
        op->func_annotations = result;
    }
    Py_INCREF(result);
    return result;
}
static PyGetSetDef __pyx_CyFunction_getsets[] = {
    {(char *) "func_doc", (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "__doc__",  (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "func_name", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__name__", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__qualname__", (getter)__Pyx_CyFunction_get_qualname, (setter)__Pyx_CyFunction_set_qualname, 0, 0},
    {(char *) "__self__", (getter)__Pyx_CyFunction_get_self, 0, 0, 0},
    {(char *) "func_dict", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "__dict__", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "func_globals", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "__globals__", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "func_closure", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "__closure__", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "func_code", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "__code__", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "func_defaults", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__defaults__", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__kwdefaults__", (getter)__Pyx_CyFunction_get_kwdefaults, (setter)__Pyx_CyFunction_set_kwdefaults, 0, 0},
    {(char *) "__annotations__", (getter)__Pyx_CyFunction_get_annotations, (setter)__Pyx_CyFunction_set_annotations, 0, 0},
    {0, 0, 0, 0, 0}
};
static PyMemberDef __pyx_CyFunction_members[] = {
    {(char *) "__module__", T_OBJECT, offsetof(PyCFunctionObject, m_module), PY_WRITE_RESTRICTED, 0},
    {0, 0, 0,  0, 0}
};
static PyObject *
__Pyx_CyFunction_reduce(__pyx_CyFunctionObject *m, CYTHON_UNUSED PyObject *args)
{
#if PY_MAJOR_VERSION >= 3
    Py_INCREF(m->func_qualname);
    return m->func_qualname;
#else
    return PyString_FromString(m->func.m_ml->ml_name);
#endif
}
static PyMethodDef __pyx_CyFunction_methods[] = {
    {"__reduce__", (PyCFunction)__Pyx_CyFunction_reduce, METH_VARARGS, 0},
    {0, 0, 0, 0}
};
#if PY_VERSION_HEX < 0x030500A0
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func_weakreflist)
#else
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func.m_weakreflist)
#endif
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject *op, PyMethodDef *ml, int flags, PyObject* qualname,
                                       PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    if (unlikely(op == NULL))
        return NULL;
    op->flags = flags;
    __Pyx_CyFunction_weakreflist(op) = NULL;
    op->func.m_ml = ml;
    op->func.m_self = (PyObject *) op;
    Py_XINCREF(closure);
    op->func_closure = closure;
    Py_XINCREF(module);
    op->func.m_module = module;
    op->func_dict = NULL;
    op->func_name = NULL;
    Py_INCREF(qualname);
    op->func_qualname = qualname;
    op->func_doc = NULL;
    op->func_classobj = NULL;
    op->func_globals = globals;
    Py_INCREF(op->func_globals);
    Py_XINCREF(code);
    op->func_code = code;
    op->defaults_pyobjects = 0;
    op->defaults_size = 0;
    op->defaults = NULL;
    op->defaults_tuple = NULL;
    op->defaults_kwdict = NULL;
    op->defaults_getter = NULL;
    op->func_annotations = NULL;
    return (PyObject *) op;
}
static int
__Pyx_CyFunction_clear(__pyx_CyFunctionObject *m)
{
    Py_CLEAR(m->func_closure);
    Py_CLEAR(m->func.m_module);
    Py_CLEAR(m->func_dict);
    Py_CLEAR(m->func_name);
    Py_CLEAR(m->func_qualname);
    Py_CLEAR(m->func_doc);
    Py_CLEAR(m->func_globals);
    Py_CLEAR(m->func_code);
    Py_CLEAR(m->func_classobj);
    Py_CLEAR(m->defaults_tuple);
    Py_CLEAR(m->defaults_kwdict);
    Py_CLEAR(m->func_annotations);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_XDECREF(pydefaults[i]);
        PyObject_Free(m->defaults);
        m->defaults = NULL;
    }
    return 0;
}
static void __Pyx__CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    if (__Pyx_CyFunction_weakreflist(m) != NULL)
        PyObject_ClearWeakRefs((PyObject *) m);
    __Pyx_CyFunction_clear(m);
    PyObject_GC_Del(m);
}
static void __Pyx_CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    PyObject_GC_UnTrack(m);
    __Pyx__CyFunction_dealloc(m);
}
static int __Pyx_CyFunction_traverse(__pyx_CyFunctionObject *m, visitproc visit, void *arg)
{
    Py_VISIT(m->func_closure);
    Py_VISIT(m->func.m_module);
    Py_VISIT(m->func_dict);
    Py_VISIT(m->func_name);
    Py_VISIT(m->func_qualname);
    Py_VISIT(m->func_doc);
    Py_VISIT(m->func_globals);
    Py_VISIT(m->func_code);
    Py_VISIT(m->func_classobj);
    Py_VISIT(m->defaults_tuple);
    Py_VISIT(m->defaults_kwdict);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_VISIT(pydefaults[i]);
    }
    return 0;
}
static PyObject *__Pyx_CyFunction_descr_get(PyObject *func, PyObject *obj, PyObject *type)
{
#if PY_MAJOR_VERSION < 3
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    if (m->flags & __Pyx_CYFUNCTION_STATICMETHOD) {
        Py_INCREF(func);
        return func;
    }
    if (m->flags & __Pyx_CYFUNCTION_CLASSMETHOD) {
        if (type == NULL)
            type = (PyObject *)(Py_TYPE(obj));
        return __Pyx_PyMethod_New(func, type, (PyObject *)(Py_TYPE(type)));
    }
    if (obj == Py_None)
        obj = NULL;
#endif
    return __Pyx_PyMethod_New(func, obj, type);
}
static PyObject*
__Pyx_CyFunction_repr(__pyx_CyFunctionObject *op)
{
#if PY_MAJOR_VERSION >= 3
    return PyUnicode_FromFormat("<cyfunction %U at %p>",
                                op->func_qualname, (void *)op);
#else
    return PyString_FromFormat("<cyfunction %s at %p>",
                               PyString_AsString(op->func_qualname), (void *)op);
#endif
}
static PyObject * __Pyx_CyFunction_CallMethod(PyObject *func, PyObject *self, PyObject *arg, PyObject *kw) {
    PyCFunctionObject* f = (PyCFunctionObject*)func;
    PyCFunction meth = f->m_ml->ml_meth;
    Py_ssize_t size;
    switch (f->m_ml->ml_flags & (METH_VARARGS | METH_KEYWORDS | METH_NOARGS | METH_O)) {
    case METH_VARARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0))
            return (*meth)(self, arg);
        break;
    case METH_VARARGS | METH_KEYWORDS:
        return (*(PyCFunctionWithKeywords)(void*)meth)(self, arg, kw);
    case METH_NOARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 0))
                return (*meth)(self, NULL);
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes no arguments (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    case METH_O:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 1)) {
                PyObject *result, *arg0;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                arg0 = PyTuple_GET_ITEM(arg, 0);
                #else
                arg0 = PySequence_ITEM(arg, 0); if (unlikely(!arg0)) return NULL;
                #endif
                result = (*meth)(self, arg0);
                #if !(CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
                Py_DECREF(arg0);
                #endif
                return result;
            }
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes exactly one argument (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    default:
        PyErr_SetString(PyExc_SystemError, "Bad call flags in "
                        "__Pyx_CyFunction_Call. METH_OLDARGS is no "
                        "longer supported!");
        return NULL;
    }
    PyErr_Format(PyExc_TypeError, "%.200s() takes no keyword arguments",
                 f->m_ml->ml_name);
    return NULL;
}
static CYTHON_INLINE PyObject *__Pyx_CyFunction_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    return __Pyx_CyFunction_CallMethod(func, ((PyCFunctionObject*)func)->m_self, arg, kw);
}
static PyObject *__Pyx_CyFunction_CallAsMethod(PyObject *func, PyObject *args, PyObject *kw) {
    PyObject *result;
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *) func;
    if ((cyfunc->flags & __Pyx_CYFUNCTION_CCLASS) && !(cyfunc->flags & __Pyx_CYFUNCTION_STATICMETHOD)) {
        Py_ssize_t argc;
        PyObject *new_args;
        PyObject *self;
        argc = PyTuple_GET_SIZE(args);
        new_args = PyTuple_GetSlice(args, 1, argc);
        if (unlikely(!new_args))
            return NULL;
        self = PyTuple_GetItem(args, 0);
        if (unlikely(!self)) {
            Py_DECREF(new_args);
#if PY_MAJOR_VERSION > 2
            PyErr_Format(PyExc_TypeError,
                         "unbound method %.200S() needs an argument",
                         cyfunc->func_qualname);
#else
            PyErr_SetString(PyExc_TypeError,
                            "unbound method needs an argument");
#endif
            return NULL;
        }
        result = __Pyx_CyFunction_CallMethod(func, self, new_args, kw);
        Py_DECREF(new_args);
    } else {
        result = __Pyx_CyFunction_Call(func, args, kw);
    }
    return result;
}
static PyTypeObject __pyx_CyFunctionType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    "cython_function_or_method",
    sizeof(__pyx_CyFunctionObject),
    0,
    (destructor) __Pyx_CyFunction_dealloc,
    0,
    0,
    0,
#if PY_MAJOR_VERSION < 3
    0,
#else
    0,
#endif
    (reprfunc) __Pyx_CyFunction_repr,
    0,
    0,
    0,
    0,
    __Pyx_CyFunction_CallAsMethod,
    0,
    0,
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC,
    0,
    (traverseproc) __Pyx_CyFunction_traverse,
    (inquiry) __Pyx_CyFunction_clear,
    0,
#if PY_VERSION_HEX < 0x030500A0
    offsetof(__pyx_CyFunctionObject, func_weakreflist),
#else
    offsetof(PyCFunctionObject, m_weakreflist),
#endif
    0,
    0,
    __pyx_CyFunction_methods,
    __pyx_CyFunction_members,
    __pyx_CyFunction_getsets,
    0,
    0,
    __Pyx_CyFunction_descr_get,
    0,
    offsetof(__pyx_CyFunctionObject, func_dict),
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#if PY_VERSION_HEX >= 0x030400a1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
    0,
#endif
#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
    0,
#endif
};
static int __pyx_CyFunction_init(void) {
    __pyx_CyFunctionType = __Pyx_FetchCommonType(&__pyx_CyFunctionType_type);
    if (unlikely(__pyx_CyFunctionType == NULL)) {
        return -1;
    }
    return 0;
}
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *func, size_t size, int pyobjects) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults = PyObject_Malloc(size);
    if (unlikely(!m->defaults))
        return PyErr_NoMemory();
    memset(m->defaults, 0, size);
    m->defaults_pyobjects = pyobjects;
    m->defaults_size = size;
    return m->defaults;
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *func, PyObject *tuple) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_tuple = tuple;
    Py_INCREF(tuple);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_kwdict = dict;
    Py_INCREF(dict);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->func_annotations = dict;
    Py_INCREF(dict);
}


static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml, int flags, PyObject* qualname,
                                      PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    PyObject *op = __Pyx_CyFunction_Init(
        PyObject_GC_New(__pyx_CyFunctionObject, __pyx_CyFunctionType),
        ml, flags, qualname, closure, module, globals, code
    );
    if (likely(op)) {
        PyObject_GC_Track(op);
    }
    return op;
}


#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem *
__Pyx_PyErr_GetTopmostException(PyThreadState *tstate)
{
    _PyErr_StackItem *exc_info = tstate->exc_info;
    while ((exc_info->exc_type == NULL || exc_info->exc_type == Py_None) &&
           exc_info->previous_item != NULL)
    {
        exc_info = exc_info->previous_item;
    }
    return exc_info;
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = __Pyx_PyErr_GetTopmostException(tstate);
    *type = exc_info->exc_type;
    *value = exc_info->exc_value;
    *tb = exc_info->exc_traceback;
    #else
    *type = tstate->exc_type;
    *value = tstate->exc_value;
    *tb = tstate->exc_traceback;
    #endif
    Py_XINCREF(*type);
    Py_XINCREF(*value);
    Py_XINCREF(*tb);
}
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = type;
    exc_info->exc_value = value;
    exc_info->exc_traceback = tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = type;
    tstate->exc_value = value;
    tstate->exc_traceback = tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
#endif


#if CYTHON_FAST_THREAD_STATE
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb)
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb)
#endif
{
    PyObject *local_type, *local_value, *local_tb;
#if CYTHON_FAST_THREAD_STATE
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    local_type = tstate->curexc_type;
    local_value = tstate->curexc_value;
    local_tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
#else
    PyErr_Fetch(&local_type, &local_value, &local_tb);
#endif
    PyErr_NormalizeException(&local_type, &local_value, &local_tb);
#if CYTHON_FAST_THREAD_STATE
    if (unlikely(tstate->curexc_type))
#else
    if (unlikely(PyErr_Occurred()))
#endif
        goto bad;
    #if PY_MAJOR_VERSION >= 3
    if (local_tb) {
        if (unlikely(PyException_SetTraceback(local_value, local_tb) < 0))
            goto bad;
    }
    #endif
    Py_XINCREF(local_tb);
    Py_XINCREF(local_type);
    Py_XINCREF(local_value);
    *type = local_type;
    *value = local_value;
    *tb = local_tb;
#if CYTHON_FAST_THREAD_STATE
    #if CYTHON_USE_EXC_INFO_STACK
    {
        _PyErr_StackItem *exc_info = tstate->exc_info;
        tmp_type = exc_info->exc_type;
        tmp_value = exc_info->exc_value;
        tmp_tb = exc_info->exc_traceback;
        exc_info->exc_type = local_type;
        exc_info->exc_value = local_value;
        exc_info->exc_traceback = local_tb;
    }
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = local_type;
    tstate->exc_value = local_value;
    tstate->exc_traceback = local_tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
#else
    PyErr_SetExcInfo(local_type, local_value, local_tb);
#endif
    return 0;
bad:
    *type = 0;
    *value = 0;
    *tb = 0;
    Py_XDECREF(local_type);
    Py_XDECREF(local_value);
    Py_XDECREF(local_tb);
    return -1;
}


#if CYTHON_FAST_THREAD_STATE
static int __Pyx_PyErr_ExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        if (__Pyx_PyErr_GivenExceptionMatches(exc_type, PyTuple_GET_ITEM(tuple, i))) return 1;
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err) {
    PyObject *exc_type = tstate->curexc_type;
    if (exc_type == err) return 1;
    if (unlikely(!exc_type)) return 0;
    if (unlikely(PyTuple_Check(err)))
        return __Pyx_PyErr_ExceptionMatchesTuple(exc_type, err);
    return __Pyx_PyErr_GivenExceptionMatches(exc_type, err);
}
#endif


static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method) {
    PyObject *attr;
#if CYTHON_UNPACK_METHODS && CYTHON_COMPILING_IN_CPYTHON && CYTHON_USE_PYTYPE_LOOKUP
    PyTypeObject *tp = Py_TYPE(obj);
    PyObject *descr;
    descrgetfunc f = NULL;
    PyObject **dictptr, *dict;
    int meth_found = 0;
    assert (*method == NULL);
    if (unlikely(tp->tp_getattro != PyObject_GenericGetAttr)) {
        attr = __Pyx_PyObject_GetAttrStr(obj, name);
        goto try_unpack;
    }
    if (unlikely(tp->tp_dict == NULL) && unlikely(PyType_Ready(tp) < 0)) {
        return 0;
    }
    descr = _PyType_Lookup(tp, name);
    if (likely(descr != NULL)) {
        Py_INCREF(descr);
#if PY_MAJOR_VERSION >= 3
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type)))
        #endif
#else
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr)))
        #endif
#endif
        {
            meth_found = 1;
        } else {
            f = Py_TYPE(descr)->tp_descr_get;
            if (f != NULL && PyDescr_IsData(descr)) {
                attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
                Py_DECREF(descr);
                goto try_unpack;
            }
        }
    }
    dictptr = _PyObject_GetDictPtr(obj);
    if (dictptr != NULL && (dict = *dictptr) != NULL) {
        Py_INCREF(dict);
        attr = __Pyx_PyDict_GetItemStr(dict, name);
        if (attr != NULL) {
            Py_INCREF(attr);
            Py_DECREF(dict);
            Py_XDECREF(descr);
            goto try_unpack;
        }
        Py_DECREF(dict);
    }
    if (meth_found) {
        *method = descr;
        return 1;
    }
    if (f != NULL) {
        attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
        Py_DECREF(descr);
        goto try_unpack;
    }
    if (descr != NULL) {
        *method = descr;
        return 0;
    }
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(name));
#endif
    return 0;
#else
    attr = __Pyx_PyObject_GetAttrStr(obj, name);
    goto try_unpack;
#endif
try_unpack:
#if CYTHON_UNPACK_METHODS
    if (likely(attr) && PyMethod_Check(attr) && likely(PyMethod_GET_SELF(attr) == obj)) {
        PyObject *function = PyMethod_GET_FUNCTION(attr);
        Py_INCREF(function);
        Py_DECREF(attr);
        *method = function;
        return 1;
    }
#endif
    *method = attr;
    return 0;
}


static PyObject* __Pyx__PyObject_CallMethod1(PyObject* method, PyObject* arg) {
    PyObject *result = __Pyx_PyObject_CallOneArg(method, arg);
    Py_DECREF(method);
    return result;
}
static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg) {
    PyObject *method = NULL, *result;
    int is_method = __Pyx_PyObject_GetMethod(obj, method_name, &method);
    if (likely(is_method)) {
        result = __Pyx_PyObject_Call2Args(method, obj, arg);
        Py_DECREF(method);
        return result;
    }
    if (unlikely(!method)) return NULL;
    return __Pyx__PyObject_CallMethod1(method, arg);
}


static CYTHON_INLINE int __Pyx_PyObject_Append(PyObject* L, PyObject* x) {
    if (likely(PyList_CheckExact(L))) {
        if (unlikely(__Pyx_PyList_Append(L, x) < 0)) return -1;
    } else {
        PyObject* retval = __Pyx_PyObject_CallMethod1(L, __pyx_n_s_append, x);
        if (unlikely(!retval))
            return -1;
        Py_DECREF(retval);
    }
    return 0;
}


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE int __Pyx_PyObject_SetAttrStr(PyObject* obj, PyObject* attr_name, PyObject* value) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_setattro))
        return tp->tp_setattro(obj, attr_name, value);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_setattr))
        return tp->tp_setattr(obj, PyString_AS_STRING(attr_name), value);
#endif
    return PyObject_SetAttr(obj, attr_name, value);
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    tmp_type = tstate->curexc_type;
    tmp_value = tstate->curexc_value;
    tmp_tb = tstate->curexc_traceback;
    tstate->curexc_type = type;
    tstate->curexc_value = value;
    tstate->curexc_traceback = tb;
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    *type = tstate->curexc_type;
    *value = tstate->curexc_value;
    *tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = *type;
    exc_info->exc_value = *value;
    exc_info->exc_traceback = *tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = *type;
    tstate->exc_value = *value;
    tstate->exc_traceback = *tb;
    #endif
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    PyErr_GetExcInfo(&tmp_type, &tmp_value, &tmp_tb);
    PyErr_SetExcInfo(*type, *value, *tb);
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#endif


#ifndef CYTHON_CLINE_IN_TRACEBACK
static int __Pyx_CLineForTraceback(CYTHON_UNUSED PyThreadState *tstate, int c_line) {
    PyObject *use_cline;
    PyObject *ptype, *pvalue, *ptraceback;
#if CYTHON_COMPILING_IN_CPYTHON
    PyObject **cython_runtime_dict;
#endif
    if (unlikely(!__pyx_cython_runtime)) {
        return c_line;
    }
    __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
#if CYTHON_COMPILING_IN_CPYTHON
    cython_runtime_dict = _PyObject_GetDictPtr(__pyx_cython_runtime);
    if (likely(cython_runtime_dict)) {
        __PYX_PY_DICT_LOOKUP_IF_MODIFIED(
            use_cline, *cython_runtime_dict,
            __Pyx_PyDict_GetItemStr(*cython_runtime_dict, __pyx_n_s_cline_in_traceback))
    } else
#endif
    {
      PyObject *use_cline_obj = __Pyx_PyObject_GetAttrStr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback);
      if (use_cline_obj) {
        use_cline = PyObject_Not(use_cline_obj) ? Py_False : Py_True;
        Py_DECREF(use_cline_obj);
      } else {
        PyErr_Clear();
        use_cline = NULL;
      }
    }
    if (!use_cline) {
        c_line = 0;
        (void) PyObject_SetAttr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback, Py_False);
    }
    else if (use_cline == Py_False || (use_cline != Py_True && PyObject_Not(use_cline) != 0)) {
        c_line = 0;
    }
    __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
    return c_line;
}
#endif


static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line) {
    int start = 0, mid = 0, end = count - 1;
    if (end >= 0 && code_line > entries[end].code_line) {
        return count;
    }
    while (start < end) {
        mid = start + (end - start) / 2;
        if (code_line < entries[mid].code_line) {
            end = mid;
        } else if (code_line > entries[mid].code_line) {
             start = mid + 1;
        } else {
            return mid;
        }
    }
    if (code_line <= entries[mid].code_line) {
        return mid;
    } else {
        return mid + 1;
    }
}
static PyCodeObject *__pyx_find_code_object(int code_line) {
    PyCodeObject* code_object;
    int pos;
    if (unlikely(!code_line) || unlikely(!__pyx_code_cache.entries)) {
        return NULL;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if (unlikely(pos >= __pyx_code_cache.count) || unlikely(__pyx_code_cache.entries[pos].code_line != code_line)) {
        return NULL;
    }
    code_object = __pyx_code_cache.entries[pos].code_object;
    Py_INCREF(code_object);
    return code_object;
}
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object) {
    int pos, i;
    __Pyx_CodeObjectCacheEntry* entries = __pyx_code_cache.entries;
    if (unlikely(!code_line)) {
        return;
    }
    if (unlikely(!entries)) {
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Malloc(64*sizeof(__Pyx_CodeObjectCacheEntry));
        if (likely(entries)) {
            __pyx_code_cache.entries = entries;
            __pyx_code_cache.max_count = 64;
            __pyx_code_cache.count = 1;
            entries[0].code_line = code_line;
            entries[0].code_object = code_object;
            Py_INCREF(code_object);
        }
        return;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if ((pos < __pyx_code_cache.count) && unlikely(__pyx_code_cache.entries[pos].code_line == code_line)) {
        PyCodeObject* tmp = entries[pos].code_object;
        entries[pos].code_object = code_object;
        Py_DECREF(tmp);
        return;
    }
    if (__pyx_code_cache.count == __pyx_code_cache.max_count) {
        int new_max = __pyx_code_cache.max_count + 64;
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Realloc(
            __pyx_code_cache.entries, ((size_t)new_max) * sizeof(__Pyx_CodeObjectCacheEntry));
        if (unlikely(!entries)) {
            return;
        }
        __pyx_code_cache.entries = entries;
        __pyx_code_cache.max_count = new_max;
    }
    for (i=__pyx_code_cache.count; i>pos; i--) {
        entries[i] = entries[i-1];
    }
    entries[pos].code_line = code_line;
    entries[pos].code_object = code_object;
    __pyx_code_cache.count++;
    Py_INCREF(code_object);
}


#include "compile.h"
#include "frameobject.h"
#include "traceback.h"
#if PY_VERSION_HEX >= 0x030b00a6
  #ifndef Py_BUILD_CORE
    #define Py_BUILD_CORE 1
  #endif
  #include "internal/pycore_frame.h"
#endif
static PyCodeObject* __Pyx_CreateCodeObjectForTraceback(
            const char *funcname, int c_line,
            int py_line, const char *filename) {
    PyCodeObject *py_code = NULL;
    PyObject *py_funcname = NULL;
    #if PY_MAJOR_VERSION < 3
    PyObject *py_srcfile = NULL;
    py_srcfile = PyString_FromString(filename);
    if (!py_srcfile) goto bad;
    #endif
    if (c_line) {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        if (!py_funcname) goto bad;
        #else
        py_funcname = PyUnicode_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        if (!py_funcname) goto bad;
        funcname = PyUnicode_AsUTF8(py_funcname);
        if (!funcname) goto bad;
        #endif
    }
    else {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromString(funcname);
        if (!py_funcname) goto bad;
        #endif
    }
    #if PY_MAJOR_VERSION < 3
    py_code = __Pyx_PyCode_New(
        0,
        0,
        0,
        0,
        0,
        __pyx_empty_bytes, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        py_srcfile,   
        py_funcname,  
        py_line,
        __pyx_empty_bytes  
    );
    Py_DECREF(py_srcfile);
    #else
    py_code = PyCode_NewEmpty(filename, funcname, py_line);
    #endif
    Py_XDECREF(py_funcname);  // XDECREF since it's only set on Py3 if cline
    return py_code;
bad:
    Py_XDECREF(py_funcname);
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(py_srcfile);
    #endif
    return NULL;
}
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject *ptype, *pvalue, *ptraceback;
    if (c_line) {
        c_line = __Pyx_CLineForTraceback(tstate, c_line);
    }
    py_code = __pyx_find_code_object(c_line ? -c_line : py_line);
    if (!py_code) {
        __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
        py_code = __Pyx_CreateCodeObjectForTraceback(
            funcname, c_line, py_line, filename);
        if (!py_code) {
            /* If the code object creation fails, then we should clear the
               fetched exception references and propagate the new exception */
            Py_XDECREF(ptype);
            Py_XDECREF(pvalue);
            Py_XDECREF(ptraceback);
            goto bad;
        }
        __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
        __pyx_insert_code_object(c_line ? -c_line : py_line, py_code);
    }
    py_frame = PyFrame_New(
        tstate,            
        py_code,           
        __pyx_d,    
        0                  
    );
    if (!py_frame) goto bad;
    __Pyx_PyFrame_SetLineNumber(py_frame, py_line);
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}


#define __PYX_VERIFY_RETURN_INT(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 0)
#define __PYX_VERIFY_RETURN_INT_EXC(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 1)
#define __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, exc)\
    {\
        func_type value = func_value;\
        if (sizeof(target_type) < sizeof(func_type)) {\
            if (unlikely(value != (func_type) (target_type) value)) {\
                func_type zero = 0;\
                if (exc && unlikely(value == (func_type)-1 && PyErr_Occurred()))\
                    return (target_type) -1;\
                if (is_unsigned && unlikely(value < zero))\
                    goto raise_neg_overflow;\
                else\
                    goto raise_overflow;\
            }\
        }\
        return (target_type) value;\
    }


static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const long neg_one = (long) -1, const_zero = (long) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(long) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(long) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(long) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(long),
                                     little, !is_unsigned);
    }
}


static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *x) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const long neg_one = (long) -1, const_zero = (long) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(long) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(long, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (long) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case  1: __PYX_VERIFY_RETURN_INT(long, digit, digits[0])
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 2 * PyLong_SHIFT) {
                            return (long) (((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 3 * PyLong_SHIFT) {
                            return (long) (((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 4 * PyLong_SHIFT) {
                            return (long) (((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (long) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(long) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case -1: __PYX_VERIFY_RETURN_INT(long, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(long,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(long) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) ((((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) ((((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) ((((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(long) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            long val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (long) -1;
        }
    } else {
        long val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (long) -1;
        val = __Pyx_PyInt_As_long(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to long");
    return (long) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to long");
    return (long) -1;
}


static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *x) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const int neg_one = (int) -1, const_zero = (int) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(int) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(int, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (int) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case  1: __PYX_VERIFY_RETURN_INT(int, digit, digits[0])
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 2 * PyLong_SHIFT) {
                            return (int) (((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 3 * PyLong_SHIFT) {
                            return (int) (((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 4 * PyLong_SHIFT) {
                            return (int) (((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (int) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(int) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case -1: __PYX_VERIFY_RETURN_INT(int, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(int,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(int) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) ((((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) ((((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) ((((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(int) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            int val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (int) -1;
        }
    } else {
        int val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (int) -1;
        val = __Pyx_PyInt_As_int(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to int");
    return (int) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to int");
    return (int) -1;
}


#if CYTHON_COMPILING_IN_CPYTHON
static int __Pyx_InBases(PyTypeObject *a, PyTypeObject *b) {
    while (a) {
        a = a->tp_base;
        if (a == b)
            return 1;
    }
    return b == &PyBaseObject_Type;
}
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (a == b) return 1;
    mro = a->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            if (PyTuple_GET_ITEM(mro, i) == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    return __Pyx_InBases(a, b);
}
#if PY_MAJOR_VERSION == 2
static int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject* exc_type2) {
    PyObject *exception, *value, *tb;
    int res;
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&exception, &value, &tb);
    res = exc_type1 ? PyObject_IsSubclass(err, exc_type1) : 0;
    if (unlikely(res == -1)) {
        PyErr_WriteUnraisable(err);
        res = 0;
    }
    if (!res) {
        res = PyObject_IsSubclass(err, exc_type2);
        if (unlikely(res == -1)) {
            PyErr_WriteUnraisable(err);
            res = 0;
        }
    }
    __Pyx_ErrRestore(exception, value, tb);
    return res;
}
#else
static CYTHON_INLINE int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject *exc_type2) {
    int res = exc_type1 ? __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type1) : 0;
    if (!res) {
        res = __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type2);
    }
    return res;
}
#endif
static int __Pyx_PyErr_GivenExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    assert(PyExceptionClass_Check(exc_type));
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        PyObject *t = PyTuple_GET_ITEM(tuple, i);
        #if PY_MAJOR_VERSION < 3
        if (likely(exc_type == t)) return 1;
        #endif
        if (likely(PyExceptionClass_Check(t))) {
            if (__Pyx_inner_PyErr_GivenExceptionMatches2(exc_type, NULL, t)) return 1;
        } else {
        }
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject* exc_type) {
    if (likely(err == exc_type)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        if (likely(PyExceptionClass_Check(exc_type))) {
            return __Pyx_inner_PyErr_GivenExceptionMatches2(err, NULL, exc_type);
        } else if (likely(PyTuple_Check(exc_type))) {
            return __Pyx_PyErr_GivenExceptionMatchesTuple(err, exc_type);
        } else {
        }
    }
    return PyErr_GivenExceptionMatches(err, exc_type);
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *exc_type1, PyObject *exc_type2) {
    assert(PyExceptionClass_Check(exc_type1));
    assert(PyExceptionClass_Check(exc_type2));
    if (likely(err == exc_type1 || err == exc_type2)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        return __Pyx_inner_PyErr_GivenExceptionMatches2(err, exc_type1, exc_type2);
    }
    return (PyErr_GivenExceptionMatches(err, exc_type1) || PyErr_GivenExceptionMatches(err, exc_type2));
}
#endif


#if PY_MAJOR_VERSION < 3
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb,
                        CYTHON_UNUSED PyObject *cause) {
    __Pyx_PyThreadState_declare
    Py_XINCREF(type);
    if (!value || value == Py_None)
        value = NULL;
    else
        Py_INCREF(value);
    if (!tb || tb == Py_None)
        tb = NULL;
    else {
        Py_INCREF(tb);
        if (!PyTraceBack_Check(tb)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: arg 3 must be a traceback or None");
            goto raise_error;
        }
    }
    if (PyType_Check(type)) {
#if CYTHON_COMPILING_IN_PYPY
        if (!value) {
            Py_INCREF(Py_None);
            value = Py_None;
        }
#endif
        PyErr_NormalizeException(&type, &value, &tb);
    } else {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto raise_error;
        }
        value = type;
        type = (PyObject*) Py_TYPE(type);
        Py_INCREF(type);
        if (!PyType_IsSubtype((PyTypeObject *)type, (PyTypeObject *)PyExc_BaseException)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: exception class must be a subclass of BaseException");
            goto raise_error;
        }
    }
    __Pyx_PyThreadState_assign
    __Pyx_ErrRestore(type, value, tb);
    return;
raise_error:
    Py_XDECREF(value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
    return;
}
#else
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause) {
    PyObject* owned_instance = NULL;
    if (tb == Py_None) {
        tb = 0;
    } else if (tb && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto bad;
    }
    if (value == Py_None)
        value = 0;
    if (PyExceptionInstance_Check(type)) {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto bad;
        }
        value = type;
        type = (PyObject*) Py_TYPE(value);
    } else if (PyExceptionClass_Check(type)) {
        PyObject *instance_class = NULL;
        if (value && PyExceptionInstance_Check(value)) {
            instance_class = (PyObject*) Py_TYPE(value);
            if (instance_class != type) {
                int is_subclass = PyObject_IsSubclass(instance_class, type);
                if (!is_subclass) {
                    instance_class = NULL;
                } else if (unlikely(is_subclass == -1)) {
                    goto bad;
                } else {
                    type = instance_class;
                }
            }
        }
        if (!instance_class) {
            PyObject *args;
            if (!value)
                args = PyTuple_New(0);
            else if (PyTuple_Check(value)) {
                Py_INCREF(value);
                args = value;
            } else
                args = PyTuple_Pack(1, value);
            if (!args)
                goto bad;
            owned_instance = PyObject_Call(type, args, NULL);
            Py_DECREF(args);
            if (!owned_instance)
                goto bad;
            value = owned_instance;
            if (!PyExceptionInstance_Check(value)) {
                PyErr_Format(PyExc_TypeError,
                             "calling %R should have returned an instance of "
                             "BaseException, not %R",
                             type, Py_TYPE(value));
                goto bad;
            }
        }
    } else {
        PyErr_SetString(PyExc_TypeError,
            "raise: exception class must be a subclass of BaseException");
        goto bad;
    }
    if (cause) {
        PyObject *fixed_cause;
        if (cause == Py_None) {
            fixed_cause = NULL;
        } else if (PyExceptionClass_Check(cause)) {
            fixed_cause = PyObject_CallObject(cause, NULL);
            if (fixed_cause == NULL)
                goto bad;
        } else if (PyExceptionInstance_Check(cause)) {
            fixed_cause = cause;
            Py_INCREF(fixed_cause);
        } else {
            PyErr_SetString(PyExc_TypeError,
                            "exception causes must derive from "
                            "BaseException");
            goto bad;
        }
        PyException_SetCause(value, fixed_cause);
    }
    PyErr_SetObject(type, value);
    if (tb) {
#if CYTHON_FAST_THREAD_STATE
        PyThreadState *tstate = __Pyx_PyThreadState_Current;
        PyObject* tmp_tb = tstate->curexc_traceback;
        if (tb != tmp_tb) {
            Py_INCREF(tb);
            tstate->curexc_traceback = tb;
            Py_XDECREF(tmp_tb);
        }
#else
        PyObject *tmp_type, *tmp_value, *tmp_tb;
        PyErr_Fetch(&tmp_type, &tmp_value, &tmp_tb);
        Py_INCREF(tb);
        PyErr_Restore(tmp_type, tmp_value, tb);
        Py_XDECREF(tmp_tb);
#endif
    }
bad:
    Py_XDECREF(owned_instance);
    return;
}
#endif


#include <structmember.h>
#include <frameobject.h>
#if PY_VERSION_HEX >= 0x030b00a6
  #ifndef Py_BUILD_CORE
    #define Py_BUILD_CORE 1
  #endif
  #include "internal/pycore_frame.h"
#endif
#define __Pyx_Coroutine_Undelegate(gen) Py_CLEAR((gen)->yieldfrom)
static int __Pyx_PyGen__FetchStopIterationValue(CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject **pvalue) {
    PyObject *et, *ev, *tb;
    PyObject *value = NULL;
    __Pyx_ErrFetch(&et, &ev, &tb);
    if (!et) {
        Py_XDECREF(tb);
        Py_XDECREF(ev);
        Py_INCREF(Py_None);
        *pvalue = Py_None;
        return 0;
    }
    if (likely(et == PyExc_StopIteration)) {
        if (!ev) {
            Py_INCREF(Py_None);
            value = Py_None;
        }
#if PY_VERSION_HEX >= 0x030300A0
        else if (Py_TYPE(ev) == (PyTypeObject*)PyExc_StopIteration) {
            value = ((PyStopIterationObject *)ev)->value;
            Py_INCREF(value);
            Py_DECREF(ev);
        }
#endif
        else if (unlikely(PyTuple_Check(ev))) {
            if (PyTuple_GET_SIZE(ev) >= 1) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                value = PyTuple_GET_ITEM(ev, 0);
                Py_INCREF(value);
#else
                value = PySequence_ITEM(ev, 0);
#endif
            } else {
                Py_INCREF(Py_None);
                value = Py_None;
            }
            Py_DECREF(ev);
        }
        else if (!__Pyx_TypeCheck(ev, (PyTypeObject*)PyExc_StopIteration)) {
            value = ev;
        }
        if (likely(value)) {
            Py_XDECREF(tb);
            Py_DECREF(et);
            *pvalue = value;
            return 0;
        }
    } else if (!__Pyx_PyErr_GivenExceptionMatches(et, PyExc_StopIteration)) {
        __Pyx_ErrRestore(et, ev, tb);
        return -1;
    }
    PyErr_NormalizeException(&et, &ev, &tb);
    if (unlikely(!PyObject_TypeCheck(ev, (PyTypeObject*)PyExc_StopIteration))) {
        __Pyx_ErrRestore(et, ev, tb);
        return -1;
    }
    Py_XDECREF(tb);
    Py_DECREF(et);
#if PY_VERSION_HEX >= 0x030300A0
    value = ((PyStopIterationObject *)ev)->value;
    Py_INCREF(value);
    Py_DECREF(ev);
#else
    {
        PyObject* args = __Pyx_PyObject_GetAttrStr(ev, __pyx_n_s_args);
        Py_DECREF(ev);
        if (likely(args)) {
            value = PySequence_GetItem(args, 0);
            Py_DECREF(args);
        }
        if (unlikely(!value)) {
            __Pyx_ErrRestore(NULL, NULL, NULL);
            Py_INCREF(Py_None);
            value = Py_None;
        }
    }
#endif
    *pvalue = value;
    return 0;
}
static CYTHON_INLINE
void __Pyx_Coroutine_ExceptionClear(__Pyx_ExcInfoStruct *exc_state) {
    PyObject *t, *v, *tb;
    t = exc_state->exc_type;
    v = exc_state->exc_value;
    tb = exc_state->exc_traceback;
    exc_state->exc_type = NULL;
    exc_state->exc_value = NULL;
    exc_state->exc_traceback = NULL;
    Py_XDECREF(t);
    Py_XDECREF(v);
    Py_XDECREF(tb);
}
#define __Pyx_Coroutine_AlreadyRunningError(gen)  (__Pyx__Coroutine_AlreadyRunningError(gen), (PyObject*)NULL)
static void __Pyx__Coroutine_AlreadyRunningError(CYTHON_UNUSED __pyx_CoroutineObject *gen) {
    const char *msg;
    if ((0)) {
    #ifdef __Pyx_Coroutine_USED
    } else if (__Pyx_Coroutine_Check((PyObject*)gen)) {
        msg = "coroutine already executing";
    #endif
    #ifdef __Pyx_AsyncGen_USED
    } else if (__Pyx_AsyncGen_CheckExact((PyObject*)gen)) {
        msg = "async generator already executing";
    #endif
    } else {
        msg = "generator already executing";
    }
    PyErr_SetString(PyExc_ValueError, msg);
}
#define __Pyx_Coroutine_NotStartedError(gen)  (__Pyx__Coroutine_NotStartedError(gen), (PyObject*)NULL)
static void __Pyx__Coroutine_NotStartedError(CYTHON_UNUSED PyObject *gen) {
    const char *msg;
    if ((0)) {
    #ifdef __Pyx_Coroutine_USED
    } else if (__Pyx_Coroutine_Check(gen)) {
        msg = "can't send non-None value to a just-started coroutine";
    #endif
    #ifdef __Pyx_AsyncGen_USED
    } else if (__Pyx_AsyncGen_CheckExact(gen)) {
        msg = "can't send non-None value to a just-started async generator";
    #endif
    } else {
        msg = "can't send non-None value to a just-started generator";
    }
    PyErr_SetString(PyExc_TypeError, msg);
}
#define __Pyx_Coroutine_AlreadyTerminatedError(gen, value, closing)  (__Pyx__Coroutine_AlreadyTerminatedError(gen, value, closing), (PyObject*)NULL)
static void __Pyx__Coroutine_AlreadyTerminatedError(CYTHON_UNUSED PyObject *gen, PyObject *value, CYTHON_UNUSED int closing) {
    #ifdef __Pyx_Coroutine_USED
    if (!closing && __Pyx_Coroutine_Check(gen)) {
        PyErr_SetString(PyExc_RuntimeError, "cannot reuse already awaited coroutine");
    } else
    #endif
    if (value) {
        #ifdef __Pyx_AsyncGen_USED
        if (__Pyx_AsyncGen_CheckExact(gen))
            PyErr_SetNone(__Pyx_PyExc_StopAsyncIteration);
        else
        #endif
        PyErr_SetNone(PyExc_StopIteration);
    }
}
static
PyObject *__Pyx_Coroutine_SendEx(__pyx_CoroutineObject *self, PyObject *value, int closing) {
    __Pyx_PyThreadState_declare
    PyThreadState *tstate;
    __Pyx_ExcInfoStruct *exc_state;
    PyObject *retval;
    assert(!self->is_running);
    if (unlikely(self->resume_label == 0)) {
        if (unlikely(value && value != Py_None)) {
            return __Pyx_Coroutine_NotStartedError((PyObject*)self);
        }
    }
    if (unlikely(self->resume_label == -1)) {
        return __Pyx_Coroutine_AlreadyTerminatedError((PyObject*)self, value, closing);
    }
#if CYTHON_FAST_THREAD_STATE
    __Pyx_PyThreadState_assign
    tstate = __pyx_tstate;
#else
    tstate = __Pyx_PyThreadState_Current;
#endif
    exc_state = &self->gi_exc_state;
    if (exc_state->exc_type) {
        #if CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_PYSTON
        #else
        if (exc_state->exc_traceback) {
            PyTracebackObject *tb = (PyTracebackObject *) exc_state->exc_traceback;
            PyFrameObject *f = tb->tb_frame;
            assert(f->f_back == NULL);
            #if PY_VERSION_HEX >= 0x030B00A1
            f->f_back = PyThreadState_GetFrame(tstate);
            #else
            Py_XINCREF(tstate->frame);
            f->f_back = tstate->frame;
            #endif
        }
        #endif
    }
#if CYTHON_USE_EXC_INFO_STACK
    exc_state->previous_item = tstate->exc_info;
    tstate->exc_info = exc_state;
#else
    if (exc_state->exc_type) {
        __Pyx_ExceptionSwap(&exc_state->exc_type, &exc_state->exc_value, &exc_state->exc_traceback);
    } else {
        __Pyx_Coroutine_ExceptionClear(exc_state);
        __Pyx_ExceptionSave(&exc_state->exc_type, &exc_state->exc_value, &exc_state->exc_traceback);
    }
#endif
    self->is_running = 1;
    retval = self->body((PyObject *) self, tstate, value);
    self->is_running = 0;
#if CYTHON_USE_EXC_INFO_STACK
    exc_state = &self->gi_exc_state;
    tstate->exc_info = exc_state->previous_item;
    exc_state->previous_item = NULL;
    __Pyx_Coroutine_ResetFrameBackpointer(exc_state);
#endif
    return retval;
}
static CYTHON_INLINE void __Pyx_Coroutine_ResetFrameBackpointer(__Pyx_ExcInfoStruct *exc_state) {
    PyObject *exc_tb = exc_state->exc_traceback;
    if (likely(exc_tb)) {
#if CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_PYSTON
#else
        PyTracebackObject *tb = (PyTracebackObject *) exc_tb;
        PyFrameObject *f = tb->tb_frame;
        Py_CLEAR(f->f_back);
#endif
    }
}
static CYTHON_INLINE
PyObject *__Pyx_Coroutine_MethodReturn(CYTHON_UNUSED PyObject* gen, PyObject *retval) {
    if (unlikely(!retval)) {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        if (!__Pyx_PyErr_Occurred()) {
            PyObject *exc = PyExc_StopIteration;
            #ifdef __Pyx_AsyncGen_USED
            if (__Pyx_AsyncGen_CheckExact(gen))
                exc = __Pyx_PyExc_StopAsyncIteration;
            #endif
            __Pyx_PyErr_SetNone(exc);
        }
    }
    return retval;
}
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03030000 && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
static CYTHON_INLINE
PyObject *__Pyx_PyGen_Send(PyGenObject *gen, PyObject *arg) {
#if PY_VERSION_HEX <= 0x030A00A1
    return _PyGen_Send(gen, arg);
#else
    PyObject *result;
    if (PyIter_Send((PyObject*)gen, arg ? arg : Py_None, &result) == PYGEN_RETURN) {
        if (PyAsyncGen_CheckExact(gen)) {
            assert(result == Py_None);
            PyErr_SetNone(PyExc_StopAsyncIteration);
        }
        else if (result == Py_None) {
            PyErr_SetNone(PyExc_StopIteration);
        }
        else {
            _PyGen_SetStopIterationValue(result);
        }
        Py_CLEAR(result);
    }
    return result;
#endif
}
#endif
static CYTHON_INLINE
PyObject *__Pyx_Coroutine_FinishDelegation(__pyx_CoroutineObject *gen) {
    PyObject *ret;
    PyObject *val = NULL;
    __Pyx_Coroutine_Undelegate(gen);
    __Pyx_PyGen__FetchStopIterationValue(__Pyx_PyThreadState_Current, &val);
    ret = __Pyx_Coroutine_SendEx(gen, val, 0);
    Py_XDECREF(val);
    return ret;
}
static PyObject *__Pyx_Coroutine_Send(PyObject *self, PyObject *value) {
    PyObject *retval;
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject*) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        gen->is_running = 1;
        #ifdef __Pyx_Generator_USED
        if (__Pyx_Generator_CheckExact(yf)) {
            ret = __Pyx_Coroutine_Send(yf, value);
        } else
        #endif
        #ifdef __Pyx_Coroutine_USED
        if (__Pyx_Coroutine_Check(yf)) {
            ret = __Pyx_Coroutine_Send(yf, value);
        } else
        #endif
        #ifdef __Pyx_AsyncGen_USED
        if (__pyx_PyAsyncGenASend_CheckExact(yf)) {
            ret = __Pyx_async_gen_asend_send(yf, value);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03030000 && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyGen_CheckExact(yf)) {
            ret = __Pyx_PyGen_Send((PyGenObject*)yf, value == Py_None ? NULL : value);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03050000 && defined(PyCoro_CheckExact) && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyCoro_CheckExact(yf)) {
            ret = __Pyx_PyGen_Send((PyGenObject*)yf, value == Py_None ? NULL : value);
        } else
        #endif
        {
            if (value == Py_None)
                ret = Py_TYPE(yf)->tp_iternext(yf);
            else
                ret = __Pyx_PyObject_CallMethod1(yf, __pyx_n_s_send, value);
        }
        gen->is_running = 0;
        if (likely(ret)) {
            return ret;
        }
        retval = __Pyx_Coroutine_FinishDelegation(gen);
    } else {
        retval = __Pyx_Coroutine_SendEx(gen, value, 0);
    }
    return __Pyx_Coroutine_MethodReturn(self, retval);
}
static int __Pyx_Coroutine_CloseIter(__pyx_CoroutineObject *gen, PyObject *yf) {
    PyObject *retval = NULL;
    int err = 0;
    #ifdef __Pyx_Generator_USED
    if (__Pyx_Generator_CheckExact(yf)) {
        retval = __Pyx_Coroutine_Close(yf);
        if (!retval)
            return -1;
    } else
    #endif
    #ifdef __Pyx_Coroutine_USED
    if (__Pyx_Coroutine_Check(yf)) {
        retval = __Pyx_Coroutine_Close(yf);
        if (!retval)
            return -1;
    } else
    if (__Pyx_CoroutineAwait_CheckExact(yf)) {
        retval = __Pyx_CoroutineAwait_Close((__pyx_CoroutineAwaitObject*)yf, NULL);
        if (!retval)
            return -1;
    } else
    #endif
    #ifdef __Pyx_AsyncGen_USED
    if (__pyx_PyAsyncGenASend_CheckExact(yf)) {
        retval = __Pyx_async_gen_asend_close(yf, NULL);
    } else
    if (__pyx_PyAsyncGenAThrow_CheckExact(yf)) {
        retval = __Pyx_async_gen_athrow_close(yf, NULL);
    } else
    #endif
    {
        PyObject *meth;
        gen->is_running = 1;
        meth = __Pyx_PyObject_GetAttrStr(yf, __pyx_n_s_close);
        if (unlikely(!meth)) {
            if (!PyErr_ExceptionMatches(PyExc_AttributeError)) {
                PyErr_WriteUnraisable(yf);
            }
            PyErr_Clear();
        } else {
            retval = PyObject_CallFunction(meth, NULL);
            Py_DECREF(meth);
            if (!retval)
                err = -1;
        }
        gen->is_running = 0;
    }
    Py_XDECREF(retval);
    return err;
}
static PyObject *__Pyx_Generator_Next(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject*) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        gen->is_running = 1;
        #ifdef __Pyx_Generator_USED
        if (__Pyx_Generator_CheckExact(yf)) {
            ret = __Pyx_Generator_Next(yf);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03030000 && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyGen_CheckExact(yf)) {
            ret = __Pyx_PyGen_Send((PyGenObject*)yf, NULL);
        } else
        #endif
        #ifdef __Pyx_Coroutine_USED
        if (__Pyx_Coroutine_Check(yf)) {
            ret = __Pyx_Coroutine_Send(yf, Py_None);
        } else
        #endif
            ret = Py_TYPE(yf)->tp_iternext(yf);
        gen->is_running = 0;
        if (likely(ret)) {
            return ret;
        }
        return __Pyx_Coroutine_FinishDelegation(gen);
    }
    return __Pyx_Coroutine_SendEx(gen, Py_None, 0);
}
static PyObject *__Pyx_Coroutine_Close_Method(PyObject *self, CYTHON_UNUSED PyObject *arg) {
    return __Pyx_Coroutine_Close(self);
}
static PyObject *__Pyx_Coroutine_Close(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject *retval, *raised_exception;
    PyObject *yf = gen->yieldfrom;
    int err = 0;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        Py_INCREF(yf);
        err = __Pyx_Coroutine_CloseIter(gen, yf);
        __Pyx_Coroutine_Undelegate(gen);
        Py_DECREF(yf);
    }
    if (err == 0)
        PyErr_SetNone(PyExc_GeneratorExit);
    retval = __Pyx_Coroutine_SendEx(gen, NULL, 1);
    if (unlikely(retval)) {
        const char *msg;
        Py_DECREF(retval);
        if ((0)) {
        #ifdef __Pyx_Coroutine_USED
        } else if (__Pyx_Coroutine_Check(self)) {
            msg = "coroutine ignored GeneratorExit";
        #endif
        #ifdef __Pyx_AsyncGen_USED
        } else if (__Pyx_AsyncGen_CheckExact(self)) {
#if PY_VERSION_HEX < 0x03060000
            msg = "async generator ignored GeneratorExit - might require Python 3.6+ finalisation (PEP 525)";
#else
            msg = "async generator ignored GeneratorExit";
#endif
        #endif
        } else {
            msg = "generator ignored GeneratorExit";
        }
        PyErr_SetString(PyExc_RuntimeError, msg);
        return NULL;
    }
    raised_exception = PyErr_Occurred();
    if (likely(!raised_exception || __Pyx_PyErr_GivenExceptionMatches2(raised_exception, PyExc_GeneratorExit, PyExc_StopIteration))) {
        if (raised_exception) PyErr_Clear();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
}
static PyObject *__Pyx__Coroutine_Throw(PyObject *self, PyObject *typ, PyObject *val, PyObject *tb,
                                        PyObject *args, int close_on_genexit) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        Py_INCREF(yf);
        if (__Pyx_PyErr_GivenExceptionMatches(typ, PyExc_GeneratorExit) && close_on_genexit) {
            int err = __Pyx_Coroutine_CloseIter(gen, yf);
            Py_DECREF(yf);
            __Pyx_Coroutine_Undelegate(gen);
            if (err < 0)
                return __Pyx_Coroutine_MethodReturn(self, __Pyx_Coroutine_SendEx(gen, NULL, 0));
            goto throw_here;
        }
        gen->is_running = 1;
        if (0
        #ifdef __Pyx_Generator_USED
            || __Pyx_Generator_CheckExact(yf)
        #endif
        #ifdef __Pyx_Coroutine_USED
            || __Pyx_Coroutine_Check(yf)
        #endif
            ) {
            ret = __Pyx__Coroutine_Throw(yf, typ, val, tb, args, close_on_genexit);
        #ifdef __Pyx_Coroutine_USED
        } else if (__Pyx_CoroutineAwait_CheckExact(yf)) {
            ret = __Pyx__Coroutine_Throw(((__pyx_CoroutineAwaitObject*)yf)->coroutine, typ, val, tb, args, close_on_genexit);
        #endif
        } else {
            PyObject *meth = __Pyx_PyObject_GetAttrStr(yf, __pyx_n_s_throw);
            if (unlikely(!meth)) {
                Py_DECREF(yf);
                if (!PyErr_ExceptionMatches(PyExc_AttributeError)) {
                    gen->is_running = 0;
                    return NULL;
                }
                PyErr_Clear();
                __Pyx_Coroutine_Undelegate(gen);
                gen->is_running = 0;
                goto throw_here;
            }
            if (likely(args)) {
                ret = PyObject_CallObject(meth, args);
            } else {
                ret = PyObject_CallFunctionObjArgs(meth, typ, val, tb, NULL);
            }
            Py_DECREF(meth);
        }
        gen->is_running = 0;
        Py_DECREF(yf);
        if (!ret) {
            ret = __Pyx_Coroutine_FinishDelegation(gen);
        }
        return __Pyx_Coroutine_MethodReturn(self, ret);
    }
throw_here:
    __Pyx_Raise(typ, val, tb, NULL);
    return __Pyx_Coroutine_MethodReturn(self, __Pyx_Coroutine_SendEx(gen, NULL, 0));
}
static PyObject *__Pyx_Coroutine_Throw(PyObject *self, PyObject *args) {
    PyObject *typ;
    PyObject *val = NULL;
    PyObject *tb = NULL;
    if (!PyArg_UnpackTuple(args, (char *)"throw", 1, 3, &typ, &val, &tb))
        return NULL;
    return __Pyx__Coroutine_Throw(self, typ, val, tb, args, 1);
}
static CYTHON_INLINE int __Pyx_Coroutine_traverse_excstate(__Pyx_ExcInfoStruct *exc_state, visitproc visit, void *arg) {
    Py_VISIT(exc_state->exc_type);
    Py_VISIT(exc_state->exc_value);
    Py_VISIT(exc_state->exc_traceback);
    return 0;
}
static int __Pyx_Coroutine_traverse(__pyx_CoroutineObject *gen, visitproc visit, void *arg) {
    Py_VISIT(gen->closure);
    Py_VISIT(gen->classobj);
    Py_VISIT(gen->yieldfrom);
    return __Pyx_Coroutine_traverse_excstate(&gen->gi_exc_state, visit, arg);
}
static int __Pyx_Coroutine_clear(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    Py_CLEAR(gen->closure);
    Py_CLEAR(gen->classobj);
    Py_CLEAR(gen->yieldfrom);
    __Pyx_Coroutine_ExceptionClear(&gen->gi_exc_state);
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        Py_CLEAR(((__pyx_PyAsyncGenObject*)gen)->ag_finalizer);
    }
#endif
    Py_CLEAR(gen->gi_code);
    Py_CLEAR(gen->gi_frame);
    Py_CLEAR(gen->gi_name);
    Py_CLEAR(gen->gi_qualname);
    Py_CLEAR(gen->gi_modulename);
    return 0;
}
static void __Pyx_Coroutine_dealloc(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject_GC_UnTrack(gen);
    if (gen->gi_weakreflist != NULL)
        PyObject_ClearWeakRefs(self);
    if (gen->resume_label >= 0) {
        PyObject_GC_Track(self);
#if PY_VERSION_HEX >= 0x030400a1 && CYTHON_USE_TP_FINALIZE
        if (PyObject_CallFinalizerFromDealloc(self))
#else
        Py_TYPE(gen)->tp_del(self);
        if (Py_REFCNT(self) > 0)
#endif
        {
            return;
        }
        PyObject_GC_UnTrack(self);
    }
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        /* We have to handle this case for asynchronous generators
           right here, because this code has to be between UNTRACK
           and GC_Del. */
        Py_CLEAR(((__pyx_PyAsyncGenObject*)self)->ag_finalizer);
    }
#endif
    __Pyx_Coroutine_clear(self);
    PyObject_GC_Del(gen);
}
static void __Pyx_Coroutine_del(PyObject *self) {
    PyObject *error_type, *error_value, *error_traceback;
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    __Pyx_PyThreadState_declare
    if (gen->resume_label < 0) {
        return;
    }
#if !CYTHON_USE_TP_FINALIZE
    assert(self->ob_refcnt == 0);
    __Pyx_SET_REFCNT(self, 1);
#endif
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&error_type, &error_value, &error_traceback);
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        __pyx_PyAsyncGenObject *agen = (__pyx_PyAsyncGenObject*)self;
        PyObject *finalizer = agen->ag_finalizer;
        if (finalizer && !agen->ag_closed) {
            PyObject *res = __Pyx_PyObject_CallOneArg(finalizer, self);
            if (unlikely(!res)) {
                PyErr_WriteUnraisable(self);
            } else {
                Py_DECREF(res);
            }
            __Pyx_ErrRestore(error_type, error_value, error_traceback);
            return;
        }
    }
#endif
    if (unlikely(gen->resume_label == 0 && !error_value)) {
#ifdef __Pyx_Coroutine_USED
#ifdef __Pyx_Generator_USED
    if (!__Pyx_Generator_CheckExact(self))
#endif
        {
        PyObject_GC_UnTrack(self);
#if PY_MAJOR_VERSION >= 3  || defined(PyErr_WarnFormat)
        if (unlikely(PyErr_WarnFormat(PyExc_RuntimeWarning, 1, "coroutine '%.50S' was never awaited", gen->gi_qualname) < 0))
            PyErr_WriteUnraisable(self);
#else
        {PyObject *msg;
        char *cmsg;
        #if CYTHON_COMPILING_IN_PYPY
        msg = NULL;
        cmsg = (char*) "coroutine was never awaited";
        #else
        char *cname;
        PyObject *qualname;
        qualname = gen->gi_qualname;
        cname = PyString_AS_STRING(qualname);
        msg = PyString_FromFormat("coroutine '%.50s' was never awaited", cname);
        if (unlikely(!msg)) {
            PyErr_Clear();
            cmsg = (char*) "coroutine was never awaited";
        } else {
            cmsg = PyString_AS_STRING(msg);
        }
        #endif
        if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning, cmsg, 1) < 0))
            PyErr_WriteUnraisable(self);
        Py_XDECREF(msg);}
#endif
        PyObject_GC_Track(self);
        }
#endif
    } else {
        PyObject *res = __Pyx_Coroutine_Close(self);
        if (unlikely(!res)) {
            if (PyErr_Occurred())
                PyErr_WriteUnraisable(self);
        } else {
            Py_DECREF(res);
        }
    }
    __Pyx_ErrRestore(error_type, error_value, error_traceback);
#if !CYTHON_USE_TP_FINALIZE
    assert(Py_REFCNT(self) > 0);
    if (--self->ob_refcnt == 0) {
        return;
    }
    {
        Py_ssize_t refcnt = Py_REFCNT(self);
        _Py_NewReference(self);
        __Pyx_SET_REFCNT(self, refcnt);
    }
#if CYTHON_COMPILING_IN_CPYTHON
    assert(PyType_IS_GC(Py_TYPE(self)) &&
           _Py_AS_GC(self)->gc.gc_refs != _PyGC_REFS_UNTRACKED);
    _Py_DEC_REFTOTAL;
#endif
#ifdef COUNT_ALLOCS
    --Py_TYPE(self)->tp_frees;
    --Py_TYPE(self)->tp_allocs;
#endif
#endif
}
static PyObject *
__Pyx_Coroutine_get_name(__pyx_CoroutineObject *self, CYTHON_UNUSED void *context)
{
    PyObject *name = self->gi_name;
    if (unlikely(!name)) name = Py_None;
    Py_INCREF(name);
    return name;
}
static int
__Pyx_Coroutine_set_name(__pyx_CoroutineObject *self, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    tmp = self->gi_name;
    Py_INCREF(value);
    self->gi_name = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_Coroutine_get_qualname(__pyx_CoroutineObject *self, CYTHON_UNUSED void *context)
{
    PyObject *name = self->gi_qualname;
    if (unlikely(!name)) name = Py_None;
    Py_INCREF(name);
    return name;
}
static int
__Pyx_Coroutine_set_qualname(__pyx_CoroutineObject *self, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    tmp = self->gi_qualname;
    Py_INCREF(value);
    self->gi_qualname = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_Coroutine_get_frame(__pyx_CoroutineObject *self, CYTHON_UNUSED void *context)
{
    PyObject *frame = self->gi_frame;
    if (!frame) {
        if (unlikely(!self->gi_code)) {
            Py_RETURN_NONE;
        }
        frame = (PyObject *) PyFrame_New(
            PyThreadState_Get(),            
            (PyCodeObject*) self->gi_code,  
            __pyx_d,                 
            0                               
        );
        if (unlikely(!frame))
            return NULL;
        self->gi_frame = frame;
    }
    Py_INCREF(frame);
    return frame;
}
static __pyx_CoroutineObject *__Pyx__Coroutine_New(
            PyTypeObject* type, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name) {
    __pyx_CoroutineObject *gen = PyObject_GC_New(__pyx_CoroutineObject, type);
    if (unlikely(!gen))
        return NULL;
    return __Pyx__Coroutine_NewInit(gen, body, code, closure, name, qualname, module_name);
}
static __pyx_CoroutineObject *__Pyx__Coroutine_NewInit(
            __pyx_CoroutineObject *gen, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name) {
    gen->body = body;
    gen->closure = closure;
    Py_XINCREF(closure);
    gen->is_running = 0;
    gen->resume_label = 0;
    gen->classobj = NULL;
    gen->yieldfrom = NULL;
    gen->gi_exc_state.exc_type = NULL;
    gen->gi_exc_state.exc_value = NULL;
    gen->gi_exc_state.exc_traceback = NULL;
#if CYTHON_USE_EXC_INFO_STACK
    gen->gi_exc_state.previous_item = NULL;
#endif
    gen->gi_weakreflist = NULL;
    Py_XINCREF(qualname);
    gen->gi_qualname = qualname;
    Py_XINCREF(name);
    gen->gi_name = name;
    Py_XINCREF(module_name);
    gen->gi_modulename = module_name;
    Py_XINCREF(code);
    gen->gi_code = code;
    gen->gi_frame = NULL;
    PyObject_GC_Track(gen);
    return gen;
}


static PyObject* __Pyx_Coroutine_patch_module(PyObject* module, const char* py_code) {
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
    int result;
    PyObject *globals, *result_obj;
    globals = PyDict_New();  if (unlikely(!globals)) goto ignore;
    result = PyDict_SetItemString(globals, "_cython_coroutine_type",
    #ifdef __Pyx_Coroutine_USED
        (PyObject*)__pyx_CoroutineType);
    #else
        Py_None);
    #endif
    if (unlikely(result < 0)) goto ignore;
    result = PyDict_SetItemString(globals, "_cython_generator_type",
    #ifdef __Pyx_Generator_USED
        (PyObject*)__pyx_GeneratorType);
    #else
        Py_None);
    #endif
    if (unlikely(result < 0)) goto ignore;
    if (unlikely(PyDict_SetItemString(globals, "_module", module) < 0)) goto ignore;
    if (unlikely(PyDict_SetItemString(globals, "__builtins__", __pyx_b) < 0)) goto ignore;
    result_obj = PyRun_String(py_code, Py_file_input, globals, globals);
    if (unlikely(!result_obj)) goto ignore;
    Py_DECREF(result_obj);
    Py_DECREF(globals);
    return module;
ignore:
    Py_XDECREF(globals);
    PyErr_WriteUnraisable(module);
    if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning, "Cython module failed to patch module with custom type", 1) < 0)) {
        Py_DECREF(module);
        module = NULL;
    }
#else
    py_code++;
#endif
    return module;
}


#ifndef CYTHON_REGISTER_ABCS
#define CYTHON_REGISTER_ABCS 1
#endif
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
static PyObject* __Pyx_patch_abc_module(PyObject *module);
static PyObject* __Pyx_patch_abc_module(PyObject *module) {
    module = __Pyx_Coroutine_patch_module(
        module, ""
"if _cython_generator_type is not None:\n"
"    try: Generator = _module.Generator\n"
"    except AttributeError: pass\n"
"    else: Generator.register(_cython_generator_type)\n"
"if _cython_coroutine_type is not None:\n"
"    try: Coroutine = _module.Coroutine\n"
"    except AttributeError: pass\n"
"    else: Coroutine.register(_cython_coroutine_type)\n"
    );
    return module;
}
#endif
static int __Pyx_patch_abc(void) {
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
    static int abc_patched = 0;
    if (CYTHON_REGISTER_ABCS && !abc_patched) {
        PyObject *module;
        module = PyImport_ImportModule((PY_MAJOR_VERSION >= 3) ? "collections.abc" : "collections");
        if (!module) {
            PyErr_WriteUnraisable(NULL);
            if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning,
                    ((PY_MAJOR_VERSION >= 3) ?
                        "Cython module failed to register with collections.abc module" :
                        "Cython module failed to register with collections module"), 1) < 0)) {
                return -1;
            }
        } else {
            module = __Pyx_patch_abc_module(module);
            abc_patched = 1;
            if (unlikely(!module))
                return -1;
            Py_DECREF(module);
        }
        module = PyImport_ImportModule("backports_abc");
        if (module) {
            module = __Pyx_patch_abc_module(module);
            Py_XDECREF(module);
        }
        if (!module) {
            PyErr_Clear();
        }
    }
#else
    if ((0)) __Pyx_Coroutine_patch_module(NULL, NULL);
#endif
    return 0;
}


static PyMethodDef __pyx_Generator_methods[] = {
    {"send", (PyCFunction) __Pyx_Coroutine_Send, METH_O,
     (char*) PyDoc_STR("send(arg) -> send 'arg' into generator,\nreturn next yielded value or raise StopIteration.")},
    {"throw", (PyCFunction) __Pyx_Coroutine_Throw, METH_VARARGS,
     (char*) PyDoc_STR("throw(typ[,val[,tb]]) -> raise exception in generator,\nreturn next yielded value or raise StopIteration.")},
    {"close", (PyCFunction) __Pyx_Coroutine_Close_Method, METH_NOARGS,
     (char*) PyDoc_STR("close() -> raise GeneratorExit inside generator.")},
    {0, 0, 0, 0}
};
static PyMemberDef __pyx_Generator_memberlist[] = {
    {(char *) "gi_running", T_BOOL, offsetof(__pyx_CoroutineObject, is_running), READONLY, NULL},
    {(char*) "gi_yieldfrom", T_OBJECT, offsetof(__pyx_CoroutineObject, yieldfrom), READONLY,
     (char*) PyDoc_STR("object being iterated by 'yield from', or None")},
    {(char*) "gi_code", T_OBJECT, offsetof(__pyx_CoroutineObject, gi_code), READONLY, NULL},
    {0, 0, 0, 0, 0}
};
static PyGetSetDef __pyx_Generator_getsets[] = {
    {(char *) "__name__", (getter)__Pyx_Coroutine_get_name, (setter)__Pyx_Coroutine_set_name,
     (char*) PyDoc_STR("name of the generator"), 0},
    {(char *) "__qualname__", (getter)__Pyx_Coroutine_get_qualname, (setter)__Pyx_Coroutine_set_qualname,
     (char*) PyDoc_STR("qualified name of the generator"), 0},
    {(char *) "gi_frame", (getter)__Pyx_Coroutine_get_frame, NULL,
     (char*) PyDoc_STR("Frame of the generator"), 0},
    {0, 0, 0, 0, 0}
};
static PyTypeObject __pyx_GeneratorType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    "generator",
    sizeof(__pyx_CoroutineObject),
    0,
    (destructor) __Pyx_Coroutine_dealloc,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_HAVE_FINALIZE,
    0,
    (traverseproc) __Pyx_Coroutine_traverse,
    0,
    0,
    offsetof(__pyx_CoroutineObject, gi_weakreflist),
    0,
    (iternextfunc) __Pyx_Generator_Next,
    __pyx_Generator_methods,
    __pyx_Generator_memberlist,
    __pyx_Generator_getsets,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#if CYTHON_USE_TP_FINALIZE
    0,
#else
    __Pyx_Coroutine_del,
#endif
    0,
#if CYTHON_USE_TP_FINALIZE
    __Pyx_Coroutine_del,
#elif PY_VERSION_HEX >= 0x030400a1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b1 && (!CYTHON_COMPILING_IN_PYPY || PYPY_VERSION_NUM >= 0x07030800)
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
    0,
#endif
#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX >= 0x03090000
    0,
#endif
};
static int __pyx_Generator_init(void) {
    __pyx_GeneratorType_type.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
    __pyx_GeneratorType_type.tp_iter = PyObject_SelfIter;
    __pyx_GeneratorType = __Pyx_FetchCommonType(&__pyx_GeneratorType_type);
    if (unlikely(!__pyx_GeneratorType)) {
        return -1;
    }
    return 0;
}


static int __Pyx_check_binary_version(void) {
    char ctversion[5];
    int same=1, i, found_dot;
    const char* rt_from_call = Py_GetVersion();
    PyOS_snprintf(ctversion, 5, "%d.%d", PY_MAJOR_VERSION, PY_MINOR_VERSION);
    found_dot = 0;
    for (i = 0; i < 4; i++) {
        if (!ctversion[i]) {
            same = (rt_from_call[i] < '0' || rt_from_call[i] > '9');
            break;
        }
        if (rt_from_call[i] != ctversion[i]) {
            same = 0;
            break;
        }
    }
    if (!same) {
        char rtversion[5] = {'\0'};
        char message[200];
        for (i=0; i<4; ++i) {
            if (rt_from_call[i] == '.') {
                if (found_dot) break;
                found_dot = 1;
            } else if (rt_from_call[i] < '0' || rt_from_call[i] > '9') {
                break;
            }
            rtversion[i] = rt_from_call[i];
        }
        PyOS_snprintf(message, sizeof(message),
                      "compiletime version %s of module '%.100s' "
                      "does not match runtime version %s",
                      ctversion, __Pyx_MODULE_NAME, rtversion);
        return PyErr_WarnEx(NULL, message, 1);
    }
    return 0;
}


static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        #if PY_MAJOR_VERSION < 3
        if (t->is_unicode) {
            *t->p = PyUnicode_DecodeUTF8(t->s, t->n - 1, NULL);
        } else if (t->intern) {
            *t->p = PyString_InternFromString(t->s);
        } else {
            *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        }
        #else
        if (t->is_unicode | t->is_str) {
            if (t->intern) {
                *t->p = PyUnicode_InternFromString(t->s);
            } else if (t->encoding) {
                *t->p = PyUnicode_Decode(t->s, t->n - 1, t->encoding, NULL);
            } else {
                *t->p = PyUnicode_FromStringAndSize(t->s, t->n - 1);
            }
        } else {
            *t->p = PyBytes_FromStringAndSize(t->s, t->n - 1);
        }
        #endif
        if (!*t->p)
            return -1;
        if (PyObject_Hash(*t->p) == -1)
            return -1;
        ++t;
    }
    return 0;
}

static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char* c_str) {
    return __Pyx_PyUnicode_FromStringAndSize(c_str, (Py_ssize_t)strlen(c_str));
}
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject* o) {
    Py_ssize_t ignore;
    return __Pyx_PyObject_AsStringAndSize(o, &ignore);
}
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
#if !CYTHON_PEP393_ENABLED
static const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    char* defenc_c;
    PyObject* defenc = _PyUnicode_AsDefaultEncodedString(o, NULL);
    if (!defenc) return NULL;
    defenc_c = PyBytes_AS_STRING(defenc);
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    {
        char* end = defenc_c + PyBytes_GET_SIZE(defenc);
        char* c;
        for (c = defenc_c; c < end; c++) {
            if ((unsigned char) (*c) >= 128) {
                PyUnicode_AsASCIIString(o);
                return NULL;
            }
        }
    }
#endif
    *length = PyBytes_GET_SIZE(defenc);
    return defenc_c;
}
#else
static CYTHON_INLINE const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    if (unlikely(__Pyx_PyUnicode_READY(o) == -1)) return NULL;
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    if (likely(PyUnicode_IS_ASCII(o))) {
        *length = PyUnicode_GET_LENGTH(o);
        return PyUnicode_AsUTF8(o);
    } else {
        PyUnicode_AsASCIIString(o);
        return NULL;
    }
#else
    return PyUnicode_AsUTF8AndSize(o, length);
#endif
}
#endif
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
    if (
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
            __Pyx_sys_getdefaultencoding_not_ascii &&
#endif
            PyUnicode_Check(o)) {
        return __Pyx_PyUnicode_AsStringAndSize(o, length);
    } else
#endif
#if (!CYTHON_COMPILING_IN_PYPY) || (defined(PyByteArray_AS_STRING) && defined(PyByteArray_GET_SIZE))
    if (PyByteArray_Check(o)) {
        *length = PyByteArray_GET_SIZE(o);
        return PyByteArray_AS_STRING(o);
    } else
#endif
    {
        char* result;
        int r = PyBytes_AsStringAndSize(o, &result, length);
        if (unlikely(r < 0)) {
            return NULL;
        } else {
            return result;
        }
    }
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   int is_true = x == Py_True;
   if (is_true | (x == Py_False) | (x == Py_None)) return is_true;
   else return PyObject_IsTrue(x);
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject* x) {
    int retval;
    if (unlikely(!x)) return -1;
    retval = __Pyx_PyObject_IsTrue(x);
    Py_DECREF(x);
    return retval;
}
static PyObject* __Pyx_PyNumber_IntOrLongWrongResultType(PyObject* result, const char* type_name) {
#if PY_MAJOR_VERSION >= 3
    if (PyLong_Check(result)) {
        if (PyErr_WarnFormat(PyExc_DeprecationWarning, 1,
                "__int__ returned non-int (type %.200s).  "
                "The ability to return an instance of a strict subclass of int "
                "is deprecated, and may be removed in a future version of Python.",
                Py_TYPE(result)->tp_name)) {
            Py_DECREF(result);
            return NULL;
        }
        return result;
    }
#endif
    PyErr_Format(PyExc_TypeError,
                 "__%.4s__ returned non-%.4s (type %.200s)",
                 type_name, type_name, Py_TYPE(result)->tp_name);
    Py_DECREF(result);
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x) {
#if CYTHON_USE_TYPE_SLOTS
  PyNumberMethods *m;
#endif
  const char *name = NULL;
  PyObject *res = NULL;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_Check(x) || PyLong_Check(x)))
#else
  if (likely(PyLong_Check(x)))
#endif
    return __Pyx_NewRef(x);
#if CYTHON_USE_TYPE_SLOTS
  m = Py_TYPE(x)->tp_as_number;
  #if PY_MAJOR_VERSION < 3
  if (m && m->nb_int) {
    name = "int";
    res = m->nb_int(x);
  }
  else if (m && m->nb_long) {
    name = "long";
    res = m->nb_long(x);
  }
  #else
  if (likely(m && m->nb_int)) {
    name = "int";
    res = m->nb_int(x);
  }
  #endif
#else
  if (!PyBytes_CheckExact(x) && !PyUnicode_CheckExact(x)) {
    res = PyNumber_Int(x);
  }
#endif
  if (likely(res)) {
#if PY_MAJOR_VERSION < 3
    if (unlikely(!PyInt_Check(res) && !PyLong_Check(res))) {
#else
    if (unlikely(!PyLong_CheckExact(res))) {
#endif
        return __Pyx_PyNumber_IntOrLongWrongResultType(res, name);
    }
  }
  else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_TypeError,
                    "an integer is required");
  }
  return res;
}
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject *x;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_CheckExact(b))) {
    if (sizeof(Py_ssize_t) >= sizeof(long))
        return PyInt_AS_LONG(b);
    else
        return PyInt_AsSsize_t(b);
  }
#endif
  if (likely(PyLong_CheckExact(b))) {
    #if CYTHON_USE_PYLONG_INTERNALS
    const digit* digits = ((PyLongObject*)b)->ob_digit;
    const Py_ssize_t size = Py_SIZE(b);
    if (likely(__Pyx_sst_abs(size) <= 1)) {
        ival = likely(size) ? digits[0] : 0;
        if (size == -1) ival = -ival;
        return ival;
    } else {
      switch (size) {
         case 2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
      }
    }
    #endif
    return PyLong_AsSsize_t(b);
  }
  x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyInt_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}
static CYTHON_INLINE Py_hash_t __Pyx_PyIndex_AsHash_t(PyObject* o) {
  if (sizeof(Py_hash_t) == sizeof(Py_ssize_t)) {
    return (Py_hash_t) __Pyx_PyIndex_AsSsize_t(o);
#if PY_MAJOR_VERSION < 3
  } else if (likely(PyInt_CheckExact(o))) {
    return PyInt_AS_LONG(o);
#endif
  } else {
    Py_ssize_t ival;
    PyObject *x;
    x = PyNumber_Index(o);
    if (!x) return -1;
    ival = PyInt_AsLong(x);
    Py_DECREF(x);
    return ival;
  }
}
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b) {
  return b ? __Pyx_NewRef(Py_True) : __Pyx_NewRef(Py_False);
}
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t ival) {
    return PyInt_FromSize_t(ival);
}


#endif 
