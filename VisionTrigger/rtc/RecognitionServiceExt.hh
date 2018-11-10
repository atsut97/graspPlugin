// This file is generated by omniidl (C++ backend)- omniORB_4_1. Do not edit.
#ifndef __RecognitionServiceExt_hh__
#define __RecognitionServiceExt_hh__

#ifndef __CORBA_H_EXTERNAL_GUARD__
#include <omniORB4/CORBA.h>
#endif

#ifndef  USE_stub_in_nt_dll
# define USE_stub_in_nt_dll_NOT_DEFINED_RecognitionServiceExt
#endif
#ifndef  USE_core_stub_in_nt_dll
# define USE_core_stub_in_nt_dll_NOT_DEFINED_RecognitionServiceExt
#endif
#ifndef  USE_dyn_stub_in_nt_dll
# define USE_dyn_stub_in_nt_dll_NOT_DEFINED_RecognitionServiceExt
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





#ifndef __RecognitionServiceExt__
#define __RecognitionServiceExt__

class RecognitionServiceExt;
class _objref_RecognitionServiceExt;
class _impl_RecognitionServiceExt;

typedef _objref_RecognitionServiceExt* RecognitionServiceExt_ptr;
typedef RecognitionServiceExt_ptr RecognitionServiceExtRef;

class RecognitionServiceExt_Helper {
public:
  typedef RecognitionServiceExt_ptr _ptr_type;

  static _ptr_type _nil();
  static _CORBA_Boolean is_nil(_ptr_type);
  static void release(_ptr_type);
  static void duplicate(_ptr_type);
  static void marshalObjRef(_ptr_type, cdrStream&);
  static _ptr_type unmarshalObjRef(cdrStream&);
};

typedef _CORBA_ObjRef_Var<_objref_RecognitionServiceExt, RecognitionServiceExt_Helper> RecognitionServiceExt_var;
typedef _CORBA_ObjRef_OUT_arg<_objref_RecognitionServiceExt,RecognitionServiceExt_Helper > RecognitionServiceExt_out;

#endif

// interface RecognitionServiceExt
class RecognitionServiceExt {
public:
  // Declarations for this interface type.
  typedef RecognitionServiceExt_ptr _ptr_type;
  typedef RecognitionServiceExt_var _var_type;

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
  static _dyn_attr const ::CORBA::TypeCode_ptr _tc_DblSeq;

  class DblSeq_var;

  class DblSeq : public _CORBA_Unbounded_Sequence_w_FixSizeElement< ::CORBA::Double, 8, 8 >  {
  public:
    typedef DblSeq_var _var_type;
    inline DblSeq() {}
    inline DblSeq(const DblSeq& _s)
      : _CORBA_Unbounded_Sequence_w_FixSizeElement< ::CORBA::Double, 8, 8 > (_s) {}

    inline DblSeq(_CORBA_ULong _max)
      : _CORBA_Unbounded_Sequence_w_FixSizeElement< ::CORBA::Double, 8, 8 > (_max) {}
    inline DblSeq(_CORBA_ULong _max, _CORBA_ULong _len, ::CORBA::Double* _val, _CORBA_Boolean _rel=0)
      : _CORBA_Unbounded_Sequence_w_FixSizeElement< ::CORBA::Double, 8, 8 > (_max, _len, _val, _rel) {}

  

    inline DblSeq& operator = (const DblSeq& _s) {
      _CORBA_Unbounded_Sequence_w_FixSizeElement< ::CORBA::Double, 8, 8 > ::operator=(_s);
      return *this;
    }
  };

  class DblSeq_out;

  class DblSeq_var {
  public:
    inline DblSeq_var() : _pd_seq(0) {}
    inline DblSeq_var(DblSeq* _s) : _pd_seq(_s) {}
    inline DblSeq_var(const DblSeq_var& _s) {
      if( _s._pd_seq )  _pd_seq = new DblSeq(*_s._pd_seq);
      else              _pd_seq = 0;
    }
    inline ~DblSeq_var() { if( _pd_seq )  delete _pd_seq; }
      
    inline DblSeq_var& operator = (DblSeq* _s) {
      if( _pd_seq )  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline DblSeq_var& operator = (const DblSeq_var& _s) {
      if( _s._pd_seq ) {
        if( !_pd_seq )  _pd_seq = new DblSeq;
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

  

    inline DblSeq* operator -> () { return _pd_seq; }
    inline const DblSeq* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator DblSeq& () const { return *_pd_seq; }
#else
    inline operator const DblSeq& () const { return *_pd_seq; }
    inline operator DblSeq& () { return *_pd_seq; }
#endif
      
    inline const DblSeq& in() const { return *_pd_seq; }
    inline DblSeq&       inout()    { return *_pd_seq; }
    inline DblSeq*&      out() {
      if( _pd_seq ) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline DblSeq* _retn() { DblSeq* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class DblSeq_out;
    
  private:
    DblSeq* _pd_seq;
  };

  class DblSeq_out {
  public:
    inline DblSeq_out(DblSeq*& _s) : _data(_s) { _data = 0; }
    inline DblSeq_out(DblSeq_var& _s)
      : _data(_s._pd_seq) { _s = (DblSeq*) 0; }
    inline DblSeq_out(const DblSeq_out& _s) : _data(_s._data) {}
    inline DblSeq_out& operator = (const DblSeq_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline DblSeq_out& operator = (DblSeq* _s) {
      _data = _s;
      return *this;
    }
    inline operator DblSeq*&()  { return _data; }
    inline DblSeq*& ptr()       { return _data; }
    inline DblSeq* operator->() { return _data; }

    inline ::CORBA::Double& operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    DblSeq*& _data;

  private:
    DblSeq_out();
    DblSeq_out& operator=(const DblSeq_var&);
  };


};

class _objref_RecognitionServiceExt :
  public virtual ::CORBA::Object,
  public virtual omniObjRef
{
public:
  ::CORBA::Boolean startObjectRecognition();
  void setParameters(const ::RecognitionServiceExt::DblSeq& param);

  inline _objref_RecognitionServiceExt()  { _PR_setobj(0); }  // nil
  _objref_RecognitionServiceExt(omniIOR*, omniIdentity*);

protected:
  virtual ~_objref_RecognitionServiceExt();

  
private:
  virtual void* _ptrToObjRef(const char*);

  _objref_RecognitionServiceExt(const _objref_RecognitionServiceExt&);
  _objref_RecognitionServiceExt& operator = (const _objref_RecognitionServiceExt&);
  // not implemented

  friend class RecognitionServiceExt;
};

class _pof_RecognitionServiceExt : public _OMNI_NS(proxyObjectFactory) {
public:
  inline _pof_RecognitionServiceExt() : _OMNI_NS(proxyObjectFactory)(RecognitionServiceExt::_PD_repoId) {}
  virtual ~_pof_RecognitionServiceExt();

  virtual omniObjRef* newObjRef(omniIOR*,omniIdentity*);
  virtual _CORBA_Boolean is_a(const char*) const;
};

class _impl_RecognitionServiceExt :
  public virtual omniServant
{
public:
  virtual ~_impl_RecognitionServiceExt();

  virtual ::CORBA::Boolean startObjectRecognition() = 0;
  virtual void setParameters(const ::RecognitionServiceExt::DblSeq& param) = 0;
  
public:  // Really protected, workaround for xlC
  virtual _CORBA_Boolean _dispatch(omniCallHandle&);

private:
  virtual void* _ptrToInterface(const char*);
  virtual const char* _mostDerivedRepoId();
  
};


_CORBA_GLOBAL_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_RecognitionServiceExt;

#ifndef __RecognitionResultServiceExt__
#define __RecognitionResultServiceExt__

class RecognitionResultServiceExt;
class _objref_RecognitionResultServiceExt;
class _impl_RecognitionResultServiceExt;

typedef _objref_RecognitionResultServiceExt* RecognitionResultServiceExt_ptr;
typedef RecognitionResultServiceExt_ptr RecognitionResultServiceExtRef;

class RecognitionResultServiceExt_Helper {
public:
  typedef RecognitionResultServiceExt_ptr _ptr_type;

  static _ptr_type _nil();
  static _CORBA_Boolean is_nil(_ptr_type);
  static void release(_ptr_type);
  static void duplicate(_ptr_type);
  static void marshalObjRef(_ptr_type, cdrStream&);
  static _ptr_type unmarshalObjRef(cdrStream&);
};

typedef _CORBA_ObjRef_Var<_objref_RecognitionResultServiceExt, RecognitionResultServiceExt_Helper> RecognitionResultServiceExt_var;
typedef _CORBA_ObjRef_OUT_arg<_objref_RecognitionResultServiceExt,RecognitionResultServiceExt_Helper > RecognitionResultServiceExt_out;

#endif

// interface RecognitionResultServiceExt
class RecognitionResultServiceExt {
public:
  // Declarations for this interface type.
  typedef RecognitionResultServiceExt_ptr _ptr_type;
  typedef RecognitionResultServiceExt_var _var_type;

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
  static _dyn_attr const ::CORBA::TypeCode_ptr _tc_DblSeqResult;

  class DblSeqResult_var;

  class DblSeqResult : public _CORBA_Unbounded_Sequence_w_FixSizeElement< ::CORBA::Double, 8, 8 >  {
  public:
    typedef DblSeqResult_var _var_type;
    inline DblSeqResult() {}
    inline DblSeqResult(const DblSeqResult& _s)
      : _CORBA_Unbounded_Sequence_w_FixSizeElement< ::CORBA::Double, 8, 8 > (_s) {}

    inline DblSeqResult(_CORBA_ULong _max)
      : _CORBA_Unbounded_Sequence_w_FixSizeElement< ::CORBA::Double, 8, 8 > (_max) {}
    inline DblSeqResult(_CORBA_ULong _max, _CORBA_ULong _len, ::CORBA::Double* _val, _CORBA_Boolean _rel=0)
      : _CORBA_Unbounded_Sequence_w_FixSizeElement< ::CORBA::Double, 8, 8 > (_max, _len, _val, _rel) {}

  

    inline DblSeqResult& operator = (const DblSeqResult& _s) {
      _CORBA_Unbounded_Sequence_w_FixSizeElement< ::CORBA::Double, 8, 8 > ::operator=(_s);
      return *this;
    }
  };

  class DblSeqResult_out;

  class DblSeqResult_var {
  public:
    inline DblSeqResult_var() : _pd_seq(0) {}
    inline DblSeqResult_var(DblSeqResult* _s) : _pd_seq(_s) {}
    inline DblSeqResult_var(const DblSeqResult_var& _s) {
      if( _s._pd_seq )  _pd_seq = new DblSeqResult(*_s._pd_seq);
      else              _pd_seq = 0;
    }
    inline ~DblSeqResult_var() { if( _pd_seq )  delete _pd_seq; }
      
    inline DblSeqResult_var& operator = (DblSeqResult* _s) {
      if( _pd_seq )  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline DblSeqResult_var& operator = (const DblSeqResult_var& _s) {
      if( _s._pd_seq ) {
        if( !_pd_seq )  _pd_seq = new DblSeqResult;
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

  

    inline DblSeqResult* operator -> () { return _pd_seq; }
    inline const DblSeqResult* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator DblSeqResult& () const { return *_pd_seq; }
#else
    inline operator const DblSeqResult& () const { return *_pd_seq; }
    inline operator DblSeqResult& () { return *_pd_seq; }
#endif
      
    inline const DblSeqResult& in() const { return *_pd_seq; }
    inline DblSeqResult&       inout()    { return *_pd_seq; }
    inline DblSeqResult*&      out() {
      if( _pd_seq ) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline DblSeqResult* _retn() { DblSeqResult* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class DblSeqResult_out;
    
  private:
    DblSeqResult* _pd_seq;
  };

  class DblSeqResult_out {
  public:
    inline DblSeqResult_out(DblSeqResult*& _s) : _data(_s) { _data = 0; }
    inline DblSeqResult_out(DblSeqResult_var& _s)
      : _data(_s._pd_seq) { _s = (DblSeqResult*) 0; }
    inline DblSeqResult_out(const DblSeqResult_out& _s) : _data(_s._data) {}
    inline DblSeqResult_out& operator = (const DblSeqResult_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline DblSeqResult_out& operator = (DblSeqResult* _s) {
      _data = _s;
      return *this;
    }
    inline operator DblSeqResult*&()  { return _data; }
    inline DblSeqResult*& ptr()       { return _data; }
    inline DblSeqResult* operator->() { return _data; }

    inline ::CORBA::Double& operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    DblSeqResult*& _data;

  private:
    DblSeqResult_out();
    DblSeqResult_out& operator=(const DblSeqResult_var&);
  };


};

class _objref_RecognitionResultServiceExt :
  public virtual ::CORBA::Object,
  public virtual omniObjRef
{
public:
  void setEnvResults(const ::RecognitionResultServiceExt::DblSeqResult& res);

  inline _objref_RecognitionResultServiceExt()  { _PR_setobj(0); }  // nil
  _objref_RecognitionResultServiceExt(omniIOR*, omniIdentity*);

protected:
  virtual ~_objref_RecognitionResultServiceExt();

  
private:
  virtual void* _ptrToObjRef(const char*);

  _objref_RecognitionResultServiceExt(const _objref_RecognitionResultServiceExt&);
  _objref_RecognitionResultServiceExt& operator = (const _objref_RecognitionResultServiceExt&);
  // not implemented

  friend class RecognitionResultServiceExt;
};

class _pof_RecognitionResultServiceExt : public _OMNI_NS(proxyObjectFactory) {
public:
  inline _pof_RecognitionResultServiceExt() : _OMNI_NS(proxyObjectFactory)(RecognitionResultServiceExt::_PD_repoId) {}
  virtual ~_pof_RecognitionResultServiceExt();

  virtual omniObjRef* newObjRef(omniIOR*,omniIdentity*);
  virtual _CORBA_Boolean is_a(const char*) const;
};

class _impl_RecognitionResultServiceExt :
  public virtual omniServant
{
public:
  virtual ~_impl_RecognitionResultServiceExt();

  virtual void setEnvResults(const ::RecognitionResultServiceExt::DblSeqResult& res) = 0;
  
public:  // Really protected, workaround for xlC
  virtual _CORBA_Boolean _dispatch(omniCallHandle&);

private:
  virtual void* _ptrToInterface(const char*);
  virtual const char* _mostDerivedRepoId();
  
};


_CORBA_GLOBAL_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_RecognitionResultServiceExt;



class POA_RecognitionServiceExt :
  public virtual _impl_RecognitionServiceExt,
  public virtual ::PortableServer::ServantBase
{
public:
  virtual ~POA_RecognitionServiceExt();

  inline ::RecognitionServiceExt_ptr _this() {
    return (::RecognitionServiceExt_ptr) _do_this(::RecognitionServiceExt::_PD_repoId);
  }
};

class POA_RecognitionResultServiceExt :
  public virtual _impl_RecognitionResultServiceExt,
  public virtual ::PortableServer::ServantBase
{
public:
  virtual ~POA_RecognitionResultServiceExt();

  inline ::RecognitionResultServiceExt_ptr _this() {
    return (::RecognitionResultServiceExt_ptr) _do_this(::RecognitionResultServiceExt::_PD_repoId);
  }
};







#undef _core_attr
#undef _dyn_attr

void operator<<=(::CORBA::Any& _a, const RecognitionServiceExt::DblSeq& _s);
void operator<<=(::CORBA::Any& _a, RecognitionServiceExt::DblSeq* _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, RecognitionServiceExt::DblSeq*& _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const RecognitionServiceExt::DblSeq*& _sp);

void operator<<=(::CORBA::Any& _a, RecognitionServiceExt_ptr _s);
void operator<<=(::CORBA::Any& _a, RecognitionServiceExt_ptr* _s);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, RecognitionServiceExt_ptr& _s);

void operator<<=(::CORBA::Any& _a, const RecognitionResultServiceExt::DblSeqResult& _s);
void operator<<=(::CORBA::Any& _a, RecognitionResultServiceExt::DblSeqResult* _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, RecognitionResultServiceExt::DblSeqResult*& _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const RecognitionResultServiceExt::DblSeqResult*& _sp);

void operator<<=(::CORBA::Any& _a, RecognitionResultServiceExt_ptr _s);
void operator<<=(::CORBA::Any& _a, RecognitionResultServiceExt_ptr* _s);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, RecognitionResultServiceExt_ptr& _s);



inline void
RecognitionServiceExt::_marshalObjRef(::RecognitionServiceExt_ptr obj, cdrStream& s) {
  omniObjRef::_marshal(obj->_PR_getobj(),s);
}


inline void
RecognitionResultServiceExt::_marshalObjRef(::RecognitionResultServiceExt_ptr obj, cdrStream& s) {
  omniObjRef::_marshal(obj->_PR_getobj(),s);
}




#ifdef   USE_stub_in_nt_dll_NOT_DEFINED_RecognitionServiceExt
# undef  USE_stub_in_nt_dll
# undef  USE_stub_in_nt_dll_NOT_DEFINED_RecognitionServiceExt
#endif
#ifdef   USE_core_stub_in_nt_dll_NOT_DEFINED_RecognitionServiceExt
# undef  USE_core_stub_in_nt_dll
# undef  USE_core_stub_in_nt_dll_NOT_DEFINED_RecognitionServiceExt
#endif
#ifdef   USE_dyn_stub_in_nt_dll_NOT_DEFINED_RecognitionServiceExt
# undef  USE_dyn_stub_in_nt_dll
# undef  USE_dyn_stub_in_nt_dll_NOT_DEFINED_RecognitionServiceExt
#endif

#endif  // __RecognitionServiceExt_hh__

