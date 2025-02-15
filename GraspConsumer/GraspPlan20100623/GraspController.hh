// This file is generated by omniidl (C++ backend)- omniORB_4_1. Do not edit.
#ifndef __GraspController_hh__
#define __GraspController_hh__

#ifndef __CORBA_H_EXTERNAL_GUARD__
#include <omniORB4/CORBA.h>
#endif

#ifndef  USE_stub_in_nt_dll
# define USE_stub_in_nt_dll_NOT_DEFINED_GraspController
#endif
#ifndef  USE_core_stub_in_nt_dll
# define USE_core_stub_in_nt_dll_NOT_DEFINED_GraspController
#endif
#ifndef  USE_dyn_stub_in_nt_dll
# define USE_dyn_stub_in_nt_dll_NOT_DEFINED_GraspController
#endif






#ifdef USE_stub_in_nt_dll
# ifndef USE_core_stub_in_nt_dll
#  define USE_core_stub_in_nt_dll
# endif
# ifndef USE_dyn_stub_in_nt_dll
#  define USE_dyn_stub_in_nt_dll
# endif
#endif

#ifdef _core_attr
# error "A local CPP macro _core_attr has already been defined."
#else
# ifdef  USE_core_stub_in_nt_dll
#  define _core_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _core_attr
# endif
#endif

#ifdef _dyn_attr
# error "A local CPP macro _dyn_attr has already been defined."
#else
# ifdef  USE_dyn_stub_in_nt_dll
#  define _dyn_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _dyn_attr
# endif
#endif





#ifndef __GraspPlanStart__
#define __GraspPlanStart__

class GraspPlanStart;
class _objref_GraspPlanStart;
class _impl_GraspPlanStart;

typedef _objref_GraspPlanStart* GraspPlanStart_ptr;
typedef GraspPlanStart_ptr GraspPlanStartRef;

class GraspPlanStart_Helper {
public:
  typedef GraspPlanStart_ptr _ptr_type;

  static _ptr_type _nil();
  static _CORBA_Boolean is_nil(_ptr_type);
  static void release(_ptr_type);
  static void duplicate(_ptr_type);
  static void marshalObjRef(_ptr_type, cdrStream&);
  static _ptr_type unmarshalObjRef(cdrStream&);
};

typedef _CORBA_ObjRef_Var<_objref_GraspPlanStart, GraspPlanStart_Helper> GraspPlanStart_var;
typedef _CORBA_ObjRef_OUT_arg<_objref_GraspPlanStart,GraspPlanStart_Helper > GraspPlanStart_out;

#endif

// interface GraspPlanStart
class GraspPlanStart {
public:
  // Declarations for this interface type.
  typedef GraspPlanStart_ptr _ptr_type;
  typedef GraspPlanStart_var _var_type;

  static _ptr_type _duplicate(_ptr_type);
  static _ptr_type _narrow(::CORBA::Object_ptr);
  static _ptr_type _unchecked_narrow(::CORBA::Object_ptr);
  
  static _ptr_type _nil();

  static inline void _marshalObjRef(_ptr_type, cdrStream&);

  static inline _ptr_type _unmarshalObjRef(cdrStream& s) {
    omniObjRef* o = omniObjRef::_unMarshal(_PD_repoId,s);
    if (o)
      return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
    else
      return _nil();
  }

  static _core_attr const char* _PD_repoId;

  // Other IDL defined within this scope.
  static _dyn_attr const ::CORBA::TypeCode_ptr _tc_DblSequence3;

  class DblSequence3_var;

  class DblSequence3 : public _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 3, 8, 8 >  {
  public:
    typedef DblSequence3_var _var_type;
    inline DblSequence3() {}
    inline DblSequence3(const DblSequence3& _s)
      : _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 3, 8, 8 > (_s) {}

    inline DblSequence3(_CORBA_ULong _len, ::CORBA::Double* _val, _CORBA_Boolean _rel=0)
      : _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 3, 8, 8 > (_len, _val, _rel) {}

  

    inline DblSequence3& operator = (const DblSequence3& _s) {
      _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 3, 8, 8 > ::operator=(_s);
      return *this;
    }
  };

  class DblSequence3_out;

  class DblSequence3_var {
  public:
    inline DblSequence3_var() : _pd_seq(0) {}
    inline DblSequence3_var(DblSequence3* _s) : _pd_seq(_s) {}
    inline DblSequence3_var(const DblSequence3_var& _s) {
      if( _s._pd_seq )  _pd_seq = new DblSequence3(*_s._pd_seq);
      else              _pd_seq = 0;
    }
    inline ~DblSequence3_var() { if( _pd_seq )  delete _pd_seq; }
      
    inline DblSequence3_var& operator = (DblSequence3* _s) {
      if( _pd_seq )  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline DblSequence3_var& operator = (const DblSequence3_var& _s) {
      if( _s._pd_seq ) {
        if( !_pd_seq )  _pd_seq = new DblSequence3;
        *_pd_seq = *_s._pd_seq;
      } else if( _pd_seq ) {
        delete _pd_seq;
        _pd_seq = 0;
      }
      return *this;
    }
    inline ::CORBA::Double& operator [] (_CORBA_ULong _s) {
      return (*_pd_seq)[_s];
    }

  

    inline DblSequence3* operator -> () { return _pd_seq; }
    inline const DblSequence3* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator DblSequence3& () const { return *_pd_seq; }
#else
    inline operator const DblSequence3& () const { return *_pd_seq; }
    inline operator DblSequence3& () { return *_pd_seq; }
#endif
      
    inline const DblSequence3& in() const { return *_pd_seq; }
    inline DblSequence3&       inout()    { return *_pd_seq; }
    inline DblSequence3*&      out() {
      if( _pd_seq ) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline DblSequence3* _retn() { DblSequence3* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class DblSequence3_out;
    
  private:
    DblSequence3* _pd_seq;
  };

  class DblSequence3_out {
  public:
    inline DblSequence3_out(DblSequence3*& _s) : _data(_s) { _data = 0; }
    inline DblSequence3_out(DblSequence3_var& _s)
      : _data(_s._pd_seq) { _s = (DblSequence3*) 0; }
    inline DblSequence3_out(const DblSequence3_out& _s) : _data(_s._data) {}
    inline DblSequence3_out& operator = (const DblSequence3_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline DblSequence3_out& operator = (DblSequence3* _s) {
      _data = _s;
      return *this;
    }
    inline operator DblSequence3*&()  { return _data; }
    inline DblSequence3*& ptr()       { return _data; }
    inline DblSequence3* operator->() { return _data; }

    inline ::CORBA::Double& operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    DblSequence3*& _data;

  private:
    DblSequence3_out();
    DblSequence3_out& operator=(const DblSequence3_var&);
  };

  static _dyn_attr const ::CORBA::TypeCode_ptr _tc_DblSequence9;

  class DblSequence9_var;

  class DblSequence9 : public _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 9, 8, 8 >  {
  public:
    typedef DblSequence9_var _var_type;
    inline DblSequence9() {}
    inline DblSequence9(const DblSequence9& _s)
      : _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 9, 8, 8 > (_s) {}

    inline DblSequence9(_CORBA_ULong _len, ::CORBA::Double* _val, _CORBA_Boolean _rel=0)
      : _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 9, 8, 8 > (_len, _val, _rel) {}

  

    inline DblSequence9& operator = (const DblSequence9& _s) {
      _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 9, 8, 8 > ::operator=(_s);
      return *this;
    }
  };

  class DblSequence9_out;

  class DblSequence9_var {
  public:
    inline DblSequence9_var() : _pd_seq(0) {}
    inline DblSequence9_var(DblSequence9* _s) : _pd_seq(_s) {}
    inline DblSequence9_var(const DblSequence9_var& _s) {
      if( _s._pd_seq )  _pd_seq = new DblSequence9(*_s._pd_seq);
      else              _pd_seq = 0;
    }
    inline ~DblSequence9_var() { if( _pd_seq )  delete _pd_seq; }
      
    inline DblSequence9_var& operator = (DblSequence9* _s) {
      if( _pd_seq )  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline DblSequence9_var& operator = (const DblSequence9_var& _s) {
      if( _s._pd_seq ) {
        if( !_pd_seq )  _pd_seq = new DblSequence9;
        *_pd_seq = *_s._pd_seq;
      } else if( _pd_seq ) {
        delete _pd_seq;
        _pd_seq = 0;
      }
      return *this;
    }
    inline ::CORBA::Double& operator [] (_CORBA_ULong _s) {
      return (*_pd_seq)[_s];
    }

  

    inline DblSequence9* operator -> () { return _pd_seq; }
    inline const DblSequence9* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator DblSequence9& () const { return *_pd_seq; }
#else
    inline operator const DblSequence9& () const { return *_pd_seq; }
    inline operator DblSequence9& () { return *_pd_seq; }
#endif
      
    inline const DblSequence9& in() const { return *_pd_seq; }
    inline DblSequence9&       inout()    { return *_pd_seq; }
    inline DblSequence9*&      out() {
      if( _pd_seq ) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline DblSequence9* _retn() { DblSequence9* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class DblSequence9_out;
    
  private:
    DblSequence9* _pd_seq;
  };

  class DblSequence9_out {
  public:
    inline DblSequence9_out(DblSequence9*& _s) : _data(_s) { _data = 0; }
    inline DblSequence9_out(DblSequence9_var& _s)
      : _data(_s._pd_seq) { _s = (DblSequence9*) 0; }
    inline DblSequence9_out(const DblSequence9_out& _s) : _data(_s._data) {}
    inline DblSequence9_out& operator = (const DblSequence9_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline DblSequence9_out& operator = (DblSequence9* _s) {
      _data = _s;
      return *this;
    }
    inline operator DblSequence9*&()  { return _data; }
    inline DblSequence9*& ptr()       { return _data; }
    inline DblSequence9* operator->() { return _data; }

    inline ::CORBA::Double& operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    DblSequence9*& _data;

  private:
    DblSequence9_out();
    DblSequence9_out& operator=(const DblSequence9_var&);
  };


};

class _objref_GraspPlanStart :
  public virtual ::CORBA::Object,
  public virtual omniObjRef
{
public:
  void GraspPlanningStart(::CORBA::ULong ObjId, const ::GraspPlanStart::DblSequence3& objPos, const ::GraspPlanStart::DblSequence9& objOri, ::CORBA::ULong& state);
  void ReleasePlanningStart(::CORBA::ULong ObjId, const ::GraspPlanStart::DblSequence3& objPos, const ::GraspPlanStart::DblSequence9& objOri, ::CORBA::ULong& state);

  inline _objref_GraspPlanStart()  { _PR_setobj(0); }  // nil
  _objref_GraspPlanStart(omniIOR*, omniIdentity*);

protected:
  virtual ~_objref_GraspPlanStart();

  
private:
  virtual void* _ptrToObjRef(const char*);

  _objref_GraspPlanStart(const _objref_GraspPlanStart&);
  _objref_GraspPlanStart& operator = (const _objref_GraspPlanStart&);
  // not implemented

  friend class GraspPlanStart;
};

class _pof_GraspPlanStart : public _OMNI_NS(proxyObjectFactory) {
public:
  inline _pof_GraspPlanStart() : _OMNI_NS(proxyObjectFactory)(GraspPlanStart::_PD_repoId) {}
  virtual ~_pof_GraspPlanStart();

  virtual omniObjRef* newObjRef(omniIOR*,omniIdentity*);
  virtual _CORBA_Boolean is_a(const char*) const;
};

class _impl_GraspPlanStart :
  public virtual omniServant
{
public:
  virtual ~_impl_GraspPlanStart();

  virtual void GraspPlanningStart(::CORBA::ULong ObjId, const ::GraspPlanStart::DblSequence3& objPos, const ::GraspPlanStart::DblSequence9& objOri, ::CORBA::ULong& state) = 0;
  virtual void ReleasePlanningStart(::CORBA::ULong ObjId, const ::GraspPlanStart::DblSequence3& objPos, const ::GraspPlanStart::DblSequence9& objOri, ::CORBA::ULong& state) = 0;
  
public:  // Really protected, workaround for xlC
  virtual _CORBA_Boolean _dispatch(omniCallHandle&);

private:
  virtual void* _ptrToInterface(const char*);
  virtual const char* _mostDerivedRepoId();
  
};


_CORBA_GLOBAL_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_GraspPlanStart;

#ifndef __GraspPlanResult__
#define __GraspPlanResult__

class GraspPlanResult;
class _objref_GraspPlanResult;
class _impl_GraspPlanResult;

typedef _objref_GraspPlanResult* GraspPlanResult_ptr;
typedef GraspPlanResult_ptr GraspPlanResultRef;

class GraspPlanResult_Helper {
public:
  typedef GraspPlanResult_ptr _ptr_type;

  static _ptr_type _nil();
  static _CORBA_Boolean is_nil(_ptr_type);
  static void release(_ptr_type);
  static void duplicate(_ptr_type);
  static void marshalObjRef(_ptr_type, cdrStream&);
  static _ptr_type unmarshalObjRef(cdrStream&);
};

typedef _CORBA_ObjRef_Var<_objref_GraspPlanResult, GraspPlanResult_Helper> GraspPlanResult_var;
typedef _CORBA_ObjRef_OUT_arg<_objref_GraspPlanResult,GraspPlanResult_Helper > GraspPlanResult_out;

#endif

// interface GraspPlanResult
class GraspPlanResult {
public:
  // Declarations for this interface type.
  typedef GraspPlanResult_ptr _ptr_type;
  typedef GraspPlanResult_var _var_type;

  static _ptr_type _duplicate(_ptr_type);
  static _ptr_type _narrow(::CORBA::Object_ptr);
  static _ptr_type _unchecked_narrow(::CORBA::Object_ptr);
  
  static _ptr_type _nil();

  static inline void _marshalObjRef(_ptr_type, cdrStream&);

  static inline _ptr_type _unmarshalObjRef(cdrStream& s) {
    omniObjRef* o = omniObjRef::_unMarshal(_PD_repoId,s);
    if (o)
      return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
    else
      return _nil();
  }

  static _core_attr const char* _PD_repoId;

  // Other IDL defined within this scope.
  static _dyn_attr const ::CORBA::TypeCode_ptr _tc_DblSequence3;

  class DblSequence3_var;

  class DblSequence3 : public _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 3, 8, 8 >  {
  public:
    typedef DblSequence3_var _var_type;
    inline DblSequence3() {}
    inline DblSequence3(const DblSequence3& _s)
      : _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 3, 8, 8 > (_s) {}

    inline DblSequence3(_CORBA_ULong _len, ::CORBA::Double* _val, _CORBA_Boolean _rel=0)
      : _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 3, 8, 8 > (_len, _val, _rel) {}

  

    inline DblSequence3& operator = (const DblSequence3& _s) {
      _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 3, 8, 8 > ::operator=(_s);
      return *this;
    }
  };

  class DblSequence3_out;

  class DblSequence3_var {
  public:
    inline DblSequence3_var() : _pd_seq(0) {}
    inline DblSequence3_var(DblSequence3* _s) : _pd_seq(_s) {}
    inline DblSequence3_var(const DblSequence3_var& _s) {
      if( _s._pd_seq )  _pd_seq = new DblSequence3(*_s._pd_seq);
      else              _pd_seq = 0;
    }
    inline ~DblSequence3_var() { if( _pd_seq )  delete _pd_seq; }
      
    inline DblSequence3_var& operator = (DblSequence3* _s) {
      if( _pd_seq )  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline DblSequence3_var& operator = (const DblSequence3_var& _s) {
      if( _s._pd_seq ) {
        if( !_pd_seq )  _pd_seq = new DblSequence3;
        *_pd_seq = *_s._pd_seq;
      } else if( _pd_seq ) {
        delete _pd_seq;
        _pd_seq = 0;
      }
      return *this;
    }
    inline ::CORBA::Double& operator [] (_CORBA_ULong _s) {
      return (*_pd_seq)[_s];
    }

  

    inline DblSequence3* operator -> () { return _pd_seq; }
    inline const DblSequence3* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator DblSequence3& () const { return *_pd_seq; }
#else
    inline operator const DblSequence3& () const { return *_pd_seq; }
    inline operator DblSequence3& () { return *_pd_seq; }
#endif
      
    inline const DblSequence3& in() const { return *_pd_seq; }
    inline DblSequence3&       inout()    { return *_pd_seq; }
    inline DblSequence3*&      out() {
      if( _pd_seq ) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline DblSequence3* _retn() { DblSequence3* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class DblSequence3_out;
    
  private:
    DblSequence3* _pd_seq;
  };

  class DblSequence3_out {
  public:
    inline DblSequence3_out(DblSequence3*& _s) : _data(_s) { _data = 0; }
    inline DblSequence3_out(DblSequence3_var& _s)
      : _data(_s._pd_seq) { _s = (DblSequence3*) 0; }
    inline DblSequence3_out(const DblSequence3_out& _s) : _data(_s._data) {}
    inline DblSequence3_out& operator = (const DblSequence3_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline DblSequence3_out& operator = (DblSequence3* _s) {
      _data = _s;
      return *this;
    }
    inline operator DblSequence3*&()  { return _data; }
    inline DblSequence3*& ptr()       { return _data; }
    inline DblSequence3* operator->() { return _data; }

    inline ::CORBA::Double& operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    DblSequence3*& _data;

  private:
    DblSequence3_out();
    DblSequence3_out& operator=(const DblSequence3_var&);
  };

  static _dyn_attr const ::CORBA::TypeCode_ptr _tc_DblSequence9;

  class DblSequence9_var;

  class DblSequence9 : public _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 9, 8, 8 >  {
  public:
    typedef DblSequence9_var _var_type;
    inline DblSequence9() {}
    inline DblSequence9(const DblSequence9& _s)
      : _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 9, 8, 8 > (_s) {}

    inline DblSequence9(_CORBA_ULong _len, ::CORBA::Double* _val, _CORBA_Boolean _rel=0)
      : _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 9, 8, 8 > (_len, _val, _rel) {}

  

    inline DblSequence9& operator = (const DblSequence9& _s) {
      _CORBA_Bounded_Sequence_w_FixSizeElement< ::CORBA::Double, 9, 8, 8 > ::operator=(_s);
      return *this;
    }
  };

  class DblSequence9_out;

  class DblSequence9_var {
  public:
    inline DblSequence9_var() : _pd_seq(0) {}
    inline DblSequence9_var(DblSequence9* _s) : _pd_seq(_s) {}
    inline DblSequence9_var(const DblSequence9_var& _s) {
      if( _s._pd_seq )  _pd_seq = new DblSequence9(*_s._pd_seq);
      else              _pd_seq = 0;
    }
    inline ~DblSequence9_var() { if( _pd_seq )  delete _pd_seq; }
      
    inline DblSequence9_var& operator = (DblSequence9* _s) {
      if( _pd_seq )  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline DblSequence9_var& operator = (const DblSequence9_var& _s) {
      if( _s._pd_seq ) {
        if( !_pd_seq )  _pd_seq = new DblSequence9;
        *_pd_seq = *_s._pd_seq;
      } else if( _pd_seq ) {
        delete _pd_seq;
        _pd_seq = 0;
      }
      return *this;
    }
    inline ::CORBA::Double& operator [] (_CORBA_ULong _s) {
      return (*_pd_seq)[_s];
    }

  

    inline DblSequence9* operator -> () { return _pd_seq; }
    inline const DblSequence9* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator DblSequence9& () const { return *_pd_seq; }
#else
    inline operator const DblSequence9& () const { return *_pd_seq; }
    inline operator DblSequence9& () { return *_pd_seq; }
#endif
      
    inline const DblSequence9& in() const { return *_pd_seq; }
    inline DblSequence9&       inout()    { return *_pd_seq; }
    inline DblSequence9*&      out() {
      if( _pd_seq ) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline DblSequence9* _retn() { DblSequence9* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class DblSequence9_out;
    
  private:
    DblSequence9* _pd_seq;
  };

  class DblSequence9_out {
  public:
    inline DblSequence9_out(DblSequence9*& _s) : _data(_s) { _data = 0; }
    inline DblSequence9_out(DblSequence9_var& _s)
      : _data(_s._pd_seq) { _s = (DblSequence9*) 0; }
    inline DblSequence9_out(const DblSequence9_out& _s) : _data(_s._data) {}
    inline DblSequence9_out& operator = (const DblSequence9_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline DblSequence9_out& operator = (DblSequence9* _s) {
      _data = _s;
      return *this;
    }
    inline operator DblSequence9*&()  { return _data; }
    inline DblSequence9*& ptr()       { return _data; }
    inline DblSequence9* operator->() { return _data; }

    inline ::CORBA::Double& operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    DblSequence9*& _data;

  private:
    DblSequence9_out();
    DblSequence9_out& operator=(const DblSequence9_var&);
  };


};

class _objref_GraspPlanResult :
  public virtual ::CORBA::Object,
  public virtual omniObjRef
{
public:
  void GraspPlanningResult(const ::GraspPlanResult::DblSequence3& GraspPos, const ::GraspPlanResult::DblSequence9& GraspOri, const ::GraspPlanResult::DblSequence3& ApproachPos, const ::GraspPlanResult::DblSequence9& ApproachOri, ::CORBA::Double angle, ::CORBA::ULong state, ::CORBA::ULong& isContinue);
  void ReleasePlanningResult(const ::GraspPlanResult::DblSequence3& GraspPos, const ::GraspPlanResult::DblSequence9& GraspOri, const ::GraspPlanResult::DblSequence3& ApproachPos, const ::GraspPlanResult::DblSequence9& ApproachOri, ::CORBA::Double angle, ::CORBA::ULong state, ::CORBA::ULong& isContinue);

  inline _objref_GraspPlanResult()  { _PR_setobj(0); }  // nil
  _objref_GraspPlanResult(omniIOR*, omniIdentity*);

protected:
  virtual ~_objref_GraspPlanResult();

  
private:
  virtual void* _ptrToObjRef(const char*);

  _objref_GraspPlanResult(const _objref_GraspPlanResult&);
  _objref_GraspPlanResult& operator = (const _objref_GraspPlanResult&);
  // not implemented

  friend class GraspPlanResult;
};

class _pof_GraspPlanResult : public _OMNI_NS(proxyObjectFactory) {
public:
  inline _pof_GraspPlanResult() : _OMNI_NS(proxyObjectFactory)(GraspPlanResult::_PD_repoId) {}
  virtual ~_pof_GraspPlanResult();

  virtual omniObjRef* newObjRef(omniIOR*,omniIdentity*);
  virtual _CORBA_Boolean is_a(const char*) const;
};

class _impl_GraspPlanResult :
  public virtual omniServant
{
public:
  virtual ~_impl_GraspPlanResult();

  virtual void GraspPlanningResult(const ::GraspPlanResult::DblSequence3& GraspPos, const ::GraspPlanResult::DblSequence9& GraspOri, const ::GraspPlanResult::DblSequence3& ApproachPos, const ::GraspPlanResult::DblSequence9& ApproachOri, ::CORBA::Double angle, ::CORBA::ULong state, ::CORBA::ULong& isContinue) = 0;
  virtual void ReleasePlanningResult(const ::GraspPlanResult::DblSequence3& GraspPos, const ::GraspPlanResult::DblSequence9& GraspOri, const ::GraspPlanResult::DblSequence3& ApproachPos, const ::GraspPlanResult::DblSequence9& ApproachOri, ::CORBA::Double angle, ::CORBA::ULong state, ::CORBA::ULong& isContinue) = 0;
  
public:  // Really protected, workaround for xlC
  virtual _CORBA_Boolean _dispatch(omniCallHandle&);

private:
  virtual void* _ptrToInterface(const char*);
  virtual const char* _mostDerivedRepoId();
  
};


_CORBA_GLOBAL_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_GraspPlanResult;



class POA_GraspPlanStart :
  public virtual _impl_GraspPlanStart,
  public virtual ::PortableServer::ServantBase
{
public:
  virtual ~POA_GraspPlanStart();

  inline ::GraspPlanStart_ptr _this() {
    return (::GraspPlanStart_ptr) _do_this(::GraspPlanStart::_PD_repoId);
  }
};

class POA_GraspPlanResult :
  public virtual _impl_GraspPlanResult,
  public virtual ::PortableServer::ServantBase
{
public:
  virtual ~POA_GraspPlanResult();

  inline ::GraspPlanResult_ptr _this() {
    return (::GraspPlanResult_ptr) _do_this(::GraspPlanResult::_PD_repoId);
  }
};







#undef _core_attr
#undef _dyn_attr

void operator<<=(::CORBA::Any& _a, const GraspPlanStart::DblSequence3& _s);
void operator<<=(::CORBA::Any& _a, GraspPlanStart::DblSequence3* _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, GraspPlanStart::DblSequence3*& _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const GraspPlanStart::DblSequence3*& _sp);

void operator<<=(::CORBA::Any& _a, const GraspPlanStart::DblSequence9& _s);
void operator<<=(::CORBA::Any& _a, GraspPlanStart::DblSequence9* _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, GraspPlanStart::DblSequence9*& _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const GraspPlanStart::DblSequence9*& _sp);

void operator<<=(::CORBA::Any& _a, GraspPlanStart_ptr _s);
void operator<<=(::CORBA::Any& _a, GraspPlanStart_ptr* _s);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, GraspPlanStart_ptr& _s);

void operator<<=(::CORBA::Any& _a, const GraspPlanResult::DblSequence3& _s);
void operator<<=(::CORBA::Any& _a, GraspPlanResult::DblSequence3* _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, GraspPlanResult::DblSequence3*& _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const GraspPlanResult::DblSequence3*& _sp);

void operator<<=(::CORBA::Any& _a, const GraspPlanResult::DblSequence9& _s);
void operator<<=(::CORBA::Any& _a, GraspPlanResult::DblSequence9* _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, GraspPlanResult::DblSequence9*& _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const GraspPlanResult::DblSequence9*& _sp);

void operator<<=(::CORBA::Any& _a, GraspPlanResult_ptr _s);
void operator<<=(::CORBA::Any& _a, GraspPlanResult_ptr* _s);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, GraspPlanResult_ptr& _s);



inline void
GraspPlanStart::_marshalObjRef(::GraspPlanStart_ptr obj, cdrStream& s) {
  omniObjRef::_marshal(obj->_PR_getobj(),s);
}


inline void
GraspPlanResult::_marshalObjRef(::GraspPlanResult_ptr obj, cdrStream& s) {
  omniObjRef::_marshal(obj->_PR_getobj(),s);
}




#ifdef   USE_stub_in_nt_dll_NOT_DEFINED_GraspController
# undef  USE_stub_in_nt_dll
# undef  USE_stub_in_nt_dll_NOT_DEFINED_GraspController
#endif
#ifdef   USE_core_stub_in_nt_dll_NOT_DEFINED_GraspController
# undef  USE_core_stub_in_nt_dll
# undef  USE_core_stub_in_nt_dll_NOT_DEFINED_GraspController
#endif
#ifdef   USE_dyn_stub_in_nt_dll_NOT_DEFINED_GraspController
# undef  USE_dyn_stub_in_nt_dll
# undef  USE_dyn_stub_in_nt_dll_NOT_DEFINED_GraspController
#endif

#endif  // __GraspController_hh__

