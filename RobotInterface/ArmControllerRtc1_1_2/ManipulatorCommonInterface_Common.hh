// This file is generated by omniidl (C++ backend)- omniORB_4_2. Do not edit.
#ifndef __ManipulatorCommonInterface__Common_hh__
#define __ManipulatorCommonInterface__Common_hh__

#ifndef __CORBA_H_EXTERNAL_GUARD__
#include <omniORB4/CORBA.h>
#endif

#ifndef  USE_stub_in_nt_dll
# define USE_stub_in_nt_dll_NOT_DEFINED_ManipulatorCommonInterface__Common
#endif
#ifndef  USE_core_stub_in_nt_dll
# define USE_core_stub_in_nt_dll_NOT_DEFINED_ManipulatorCommonInterface__Common
#endif
#ifndef  USE_dyn_stub_in_nt_dll
# define USE_dyn_stub_in_nt_dll_NOT_DEFINED_ManipulatorCommonInterface__Common
#endif



#ifndef __BasicDataType_hh_EXTERNAL_GUARD__
#define __BasicDataType_hh_EXTERNAL_GUARD__
#include <BasicDataType.hh>
#endif
#ifndef __ManipulatorCommonInterface__DataTypes_hh_EXTERNAL_GUARD__
#define __ManipulatorCommonInterface__DataTypes_hh_EXTERNAL_GUARD__
#include <ManipulatorCommonInterface_DataTypes.hh>
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



_CORBA_MODULE RTC

_CORBA_MODULE_BEG

  enum AlarmType { FAULT, WARNING, UNKNOWN /*, __max_AlarmType=0xffffffff */ };
  typedef AlarmType& AlarmType_out;

  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_AlarmType;

  struct Alarm {
    typedef _CORBA_ConstrType_Variable_Var<Alarm> _var_type;

    
    ::CORBA::ULong code;

    AlarmType type;

    ::CORBA::String_member description;

  

    void operator>>= (cdrStream &) const;
    void operator<<= (cdrStream &);
  };

  typedef Alarm::_var_type Alarm_var;

  typedef _CORBA_ConstrType_Variable_OUT_arg< Alarm,Alarm_var > Alarm_out;

  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_Alarm;

  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_AlarmSeq;

  class AlarmSeq_var;

  class AlarmSeq : public _CORBA_Unbounded_Sequence< Alarm >  {
  public:
    typedef AlarmSeq_var _var_type;
    inline AlarmSeq() {}
    inline AlarmSeq(const AlarmSeq& _s)
      : _CORBA_Unbounded_Sequence< Alarm > (_s) {}

    inline AlarmSeq(_CORBA_ULong _max)
      : _CORBA_Unbounded_Sequence< Alarm > (_max) {}
    inline AlarmSeq(_CORBA_ULong _max, _CORBA_ULong _len, Alarm* _val, _CORBA_Boolean _rel=0)
      : _CORBA_Unbounded_Sequence< Alarm > (_max, _len, _val, _rel) {}

  

    inline AlarmSeq& operator = (const AlarmSeq& _s) {
      _CORBA_Unbounded_Sequence< Alarm > ::operator=(_s);
      return *this;
    }
  };

  class AlarmSeq_out;

  class AlarmSeq_var {
  public:
    inline AlarmSeq_var() : _pd_seq(0) {}
    inline AlarmSeq_var(AlarmSeq* _s) : _pd_seq(_s) {}
    inline AlarmSeq_var(const AlarmSeq_var& _s) {
      if (_s._pd_seq)  _pd_seq = new AlarmSeq(*_s._pd_seq);
      else             _pd_seq = 0;
    }
    inline ~AlarmSeq_var() { if (_pd_seq)  delete _pd_seq; }
      
    inline AlarmSeq_var& operator = (AlarmSeq* _s) {
      if (_pd_seq)  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline AlarmSeq_var& operator = (const AlarmSeq_var& _s) {
      if (&_s != this) {
        if (_s._pd_seq) {
          if (!_pd_seq)  _pd_seq = new AlarmSeq;
          *_pd_seq = *_s._pd_seq;
        }
        else if (_pd_seq) {
          delete _pd_seq;
          _pd_seq = 0;
        }
      }
      return *this;
    }
    inline Alarm& operator [] (_CORBA_ULong _s) {
      return (*_pd_seq)[_s];
    }

  

    inline AlarmSeq* operator -> () { return _pd_seq; }
    inline const AlarmSeq* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator AlarmSeq& () const { return *_pd_seq; }
#else
    inline operator const AlarmSeq& () const { return *_pd_seq; }
    inline operator AlarmSeq& () { return *_pd_seq; }
#endif
      
    inline const AlarmSeq& in() const { return *_pd_seq; }
    inline AlarmSeq&       inout()    { return *_pd_seq; }
    inline AlarmSeq*&      out() {
      if (_pd_seq) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline AlarmSeq* _retn() { AlarmSeq* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class AlarmSeq_out;
    
  private:
    AlarmSeq* _pd_seq;
  };

  class AlarmSeq_out {
  public:
    inline AlarmSeq_out(AlarmSeq*& _s) : _data(_s) { _data = 0; }
    inline AlarmSeq_out(AlarmSeq_var& _s)
      : _data(_s._pd_seq) { _s = (AlarmSeq*) 0; }
    inline AlarmSeq_out(const AlarmSeq_out& _s) : _data(_s._data) {}
    inline AlarmSeq_out& operator = (const AlarmSeq_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline AlarmSeq_out& operator = (AlarmSeq* _s) {
      _data = _s;
      return *this;
    }
    inline operator AlarmSeq*&()  { return _data; }
    inline AlarmSeq*& ptr()       { return _data; }
    inline AlarmSeq* operator->() { return _data; }

    inline Alarm& operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    AlarmSeq*& _data;

  private:
    AlarmSeq_out();
    AlarmSeq_out& operator=(const AlarmSeq_var&);
  };

  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_LimitSeq;

  class LimitSeq_var;

  class LimitSeq : public _CORBA_Unbounded_Sequence< LimitValue >  {
  public:
    typedef LimitSeq_var _var_type;
    inline LimitSeq() {}
    inline LimitSeq(const LimitSeq& _s)
      : _CORBA_Unbounded_Sequence< LimitValue > (_s) {}

    inline LimitSeq(_CORBA_ULong _max)
      : _CORBA_Unbounded_Sequence< LimitValue > (_max) {}
    inline LimitSeq(_CORBA_ULong _max, _CORBA_ULong _len, LimitValue* _val, _CORBA_Boolean _rel=0)
      : _CORBA_Unbounded_Sequence< LimitValue > (_max, _len, _val, _rel) {}

  

    inline LimitSeq& operator = (const LimitSeq& _s) {
      _CORBA_Unbounded_Sequence< LimitValue > ::operator=(_s);
      return *this;
    }
  };

  class LimitSeq_out;

  class LimitSeq_var {
  public:
    inline LimitSeq_var() : _pd_seq(0) {}
    inline LimitSeq_var(LimitSeq* _s) : _pd_seq(_s) {}
    inline LimitSeq_var(const LimitSeq_var& _s) {
      if (_s._pd_seq)  _pd_seq = new LimitSeq(*_s._pd_seq);
      else             _pd_seq = 0;
    }
    inline ~LimitSeq_var() { if (_pd_seq)  delete _pd_seq; }
      
    inline LimitSeq_var& operator = (LimitSeq* _s) {
      if (_pd_seq)  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline LimitSeq_var& operator = (const LimitSeq_var& _s) {
      if (&_s != this) {
        if (_s._pd_seq) {
          if (!_pd_seq)  _pd_seq = new LimitSeq;
          *_pd_seq = *_s._pd_seq;
        }
        else if (_pd_seq) {
          delete _pd_seq;
          _pd_seq = 0;
        }
      }
      return *this;
    }
    inline LimitValue& operator [] (_CORBA_ULong _s) {
      return (*_pd_seq)[_s];
    }

  

    inline LimitSeq* operator -> () { return _pd_seq; }
    inline const LimitSeq* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator LimitSeq& () const { return *_pd_seq; }
#else
    inline operator const LimitSeq& () const { return *_pd_seq; }
    inline operator LimitSeq& () { return *_pd_seq; }
#endif
      
    inline const LimitSeq& in() const { return *_pd_seq; }
    inline LimitSeq&       inout()    { return *_pd_seq; }
    inline LimitSeq*&      out() {
      if (_pd_seq) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline LimitSeq* _retn() { LimitSeq* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class LimitSeq_out;
    
  private:
    LimitSeq* _pd_seq;
  };

  class LimitSeq_out {
  public:
    inline LimitSeq_out(LimitSeq*& _s) : _data(_s) { _data = 0; }
    inline LimitSeq_out(LimitSeq_var& _s)
      : _data(_s._pd_seq) { _s = (LimitSeq*) 0; }
    inline LimitSeq_out(const LimitSeq_out& _s) : _data(_s._data) {}
    inline LimitSeq_out& operator = (const LimitSeq_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline LimitSeq_out& operator = (LimitSeq* _s) {
      _data = _s;
      return *this;
    }
    inline operator LimitSeq*&()  { return _data; }
    inline LimitSeq*& ptr()       { return _data; }
    inline LimitSeq* operator->() { return _data; }

    inline LimitValue& operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    LimitSeq*& _data;

  private:
    LimitSeq_out();
    LimitSeq_out& operator=(const LimitSeq_var&);
  };

  struct ManipInfo {
    typedef _CORBA_ConstrType_Variable_Var<ManipInfo> _var_type;

    
    ::CORBA::String_member manufactur;

    ::CORBA::String_member type;

    ULONG axisNum;

    ULONG cmdCycle;

    ::CORBA::Boolean isGripper;

  

    void operator>>= (cdrStream &) const;
    void operator<<= (cdrStream &);
  };

  typedef ManipInfo::_var_type ManipInfo_var;

  typedef _CORBA_ConstrType_Variable_OUT_arg< ManipInfo,ManipInfo_var > ManipInfo_out;

  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_ManipInfo;

  _CORBA_MODULE_VARINT const ::CORBA::ULong CONST_BINARY_00000001 _init_in_decl_( = 1U );

  _CORBA_MODULE_VARINT const ::CORBA::ULong CONST_BINARY_00000010 _init_in_decl_( = 2U );

  _CORBA_MODULE_VARINT const ::CORBA::ULong CONST_BINARY_00000100 _init_in_decl_( = 4U );

  _CORBA_MODULE_VARINT const ::CORBA::ULong CONST_BINARY_00001000 _init_in_decl_( = 8U );

_CORBA_MODULE_END

#ifndef __ManipulatorCommonInterface__Common__
#define __ManipulatorCommonInterface__Common__
class ManipulatorCommonInterface_Common;
class _objref_ManipulatorCommonInterface_Common;
class _impl_ManipulatorCommonInterface_Common;

typedef _objref_ManipulatorCommonInterface_Common* ManipulatorCommonInterface_Common_ptr;
typedef ManipulatorCommonInterface_Common_ptr ManipulatorCommonInterface_CommonRef;

class ManipulatorCommonInterface_Common_Helper {
public:
  typedef ManipulatorCommonInterface_Common_ptr _ptr_type;

  static _ptr_type _nil();
  static _CORBA_Boolean is_nil(_ptr_type);
  static void release(_ptr_type);
  static void duplicate(_ptr_type);
  static void marshalObjRef(_ptr_type, cdrStream&);
  static _ptr_type unmarshalObjRef(cdrStream&);
};

typedef _CORBA_ObjRef_Var<_objref_ManipulatorCommonInterface_Common, ManipulatorCommonInterface_Common_Helper> ManipulatorCommonInterface_Common_var;
typedef _CORBA_ObjRef_OUT_arg<_objref_ManipulatorCommonInterface_Common,ManipulatorCommonInterface_Common_Helper > ManipulatorCommonInterface_Common_out;

#endif

// interface ManipulatorCommonInterface_Common
class ManipulatorCommonInterface_Common {
public:
  // Declarations for this interface type.
  typedef ManipulatorCommonInterface_Common_ptr _ptr_type;
  typedef ManipulatorCommonInterface_Common_var _var_type;

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

  static inline _ptr_type _fromObjRef(omniObjRef* o) {
    if (o)
      return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
    else
      return _nil();
  }

  static _core_attr const char* _PD_repoId;

  // Other IDL defined within this scope.
  
};

class _objref_ManipulatorCommonInterface_Common :
  public virtual ::CORBA::Object,
  public virtual omniObjRef
{
public:
  // IDL operations
  RTC::RETURN_ID* clearAlarms();
  RTC::RETURN_ID* getActiveAlarm(::RTC::AlarmSeq_out alarms);
  RTC::RETURN_ID* getFeedbackPosJoint(::RTC::JointPos_out pos);
  RTC::RETURN_ID* getManipInfo(::RTC::ManipInfo_out manipInfo);
  RTC::RETURN_ID* getSoftLimitJoint(::RTC::LimitSeq_out softLimit);
  RTC::RETURN_ID* getState(::RTC::ULONG& state);
  RTC::RETURN_ID* servoOFF();
  RTC::RETURN_ID* servoON();
  RTC::RETURN_ID* setSoftLimitJoint(const ::RTC::LimitSeq& softLimit);

  // Constructors
  inline _objref_ManipulatorCommonInterface_Common()  { _PR_setobj(0); }  // nil
  _objref_ManipulatorCommonInterface_Common(omniIOR*, omniIdentity*);

protected:
  virtual ~_objref_ManipulatorCommonInterface_Common();

  
private:
  virtual void* _ptrToObjRef(const char*);

  _objref_ManipulatorCommonInterface_Common(const _objref_ManipulatorCommonInterface_Common&);
  _objref_ManipulatorCommonInterface_Common& operator = (const _objref_ManipulatorCommonInterface_Common&);
  // not implemented

  friend class ManipulatorCommonInterface_Common;
};

class _pof_ManipulatorCommonInterface_Common : public _OMNI_NS(proxyObjectFactory) {
public:
  inline _pof_ManipulatorCommonInterface_Common() : _OMNI_NS(proxyObjectFactory)(ManipulatorCommonInterface_Common::_PD_repoId) {}
  virtual ~_pof_ManipulatorCommonInterface_Common();

  virtual omniObjRef* newObjRef(omniIOR*,omniIdentity*);
  virtual _CORBA_Boolean is_a(const char*) const;
};

class _impl_ManipulatorCommonInterface_Common :
  public virtual omniServant
{
public:
  virtual ~_impl_ManipulatorCommonInterface_Common();

  virtual RTC::RETURN_ID* clearAlarms() = 0;
  virtual RTC::RETURN_ID* getActiveAlarm(::RTC::AlarmSeq_out alarms) = 0;
  virtual RTC::RETURN_ID* getFeedbackPosJoint(::RTC::JointPos_out pos) = 0;
  virtual RTC::RETURN_ID* getManipInfo(::RTC::ManipInfo_out manipInfo) = 0;
  virtual RTC::RETURN_ID* getSoftLimitJoint(::RTC::LimitSeq_out softLimit) = 0;
  virtual RTC::RETURN_ID* getState(::RTC::ULONG& state) = 0;
  virtual RTC::RETURN_ID* servoOFF() = 0;
  virtual RTC::RETURN_ID* servoON() = 0;
  virtual RTC::RETURN_ID* setSoftLimitJoint(const ::RTC::LimitSeq& softLimit) = 0;
  
public:  // Really protected, workaround for xlC
  virtual _CORBA_Boolean _dispatch(omniCallHandle&);

private:
  virtual void* _ptrToInterface(const char*);
  virtual const char* _mostDerivedRepoId();
  
};


_CORBA_GLOBAL_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_ManipulatorCommonInterface_Common;



_CORBA_MODULE POA_RTC
_CORBA_MODULE_BEG

_CORBA_MODULE_END

class POA_ManipulatorCommonInterface_Common :
  public virtual _impl_ManipulatorCommonInterface_Common,
  public virtual ::PortableServer::ServantBase
{
public:
  virtual ~POA_ManipulatorCommonInterface_Common();

  inline ::ManipulatorCommonInterface_Common_ptr _this() {
    return (::ManipulatorCommonInterface_Common_ptr) _do_this(::ManipulatorCommonInterface_Common::_PD_repoId);
  }
};



_CORBA_MODULE OBV_RTC
_CORBA_MODULE_BEG

_CORBA_MODULE_END





#undef _core_attr
#undef _dyn_attr

inline void operator >>=(RTC::AlarmType _e, cdrStream& s) {
  ::operator>>=((::CORBA::ULong)_e, s);
}

inline void operator <<= (RTC::AlarmType& _e, cdrStream& s) {
  ::CORBA::ULong _0RL_e;
  ::operator<<=(_0RL_e,s);
  if (_0RL_e <= RTC::UNKNOWN) {
    _e = (RTC::AlarmType) _0RL_e;
  }
  else {
    OMNIORB_THROW(MARSHAL,_OMNI_NS(MARSHAL_InvalidEnumValue),
                  (::CORBA::CompletionStatus)s.completion());
  }
}

void operator<<=(::CORBA::Any& _a, RTC::AlarmType _s);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, RTC::AlarmType& _s);

extern void operator<<=(::CORBA::Any& _a, const RTC::Alarm& _s);
extern void operator<<=(::CORBA::Any& _a, RTC::Alarm* _sp);
extern _CORBA_Boolean operator>>=(const ::CORBA::Any& _a, RTC::Alarm*& _sp);
extern _CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const RTC::Alarm*& _sp);

void operator<<=(::CORBA::Any& _a, const RTC::AlarmSeq& _s);
void operator<<=(::CORBA::Any& _a, RTC::AlarmSeq* _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, RTC::AlarmSeq*& _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const RTC::AlarmSeq*& _sp);

void operator<<=(::CORBA::Any& _a, const RTC::LimitSeq& _s);
void operator<<=(::CORBA::Any& _a, RTC::LimitSeq* _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, RTC::LimitSeq*& _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const RTC::LimitSeq*& _sp);

extern void operator<<=(::CORBA::Any& _a, const RTC::ManipInfo& _s);
extern void operator<<=(::CORBA::Any& _a, RTC::ManipInfo* _sp);
extern _CORBA_Boolean operator>>=(const ::CORBA::Any& _a, RTC::ManipInfo*& _sp);
extern _CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const RTC::ManipInfo*& _sp);

void operator<<=(::CORBA::Any& _a, ManipulatorCommonInterface_Common_ptr _s);
void operator<<=(::CORBA::Any& _a, ManipulatorCommonInterface_Common_ptr* _s);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, ManipulatorCommonInterface_Common_ptr& _s);



inline void
ManipulatorCommonInterface_Common::_marshalObjRef(::ManipulatorCommonInterface_Common_ptr obj, cdrStream& s) {
  omniObjRef::_marshal(obj->_PR_getobj(),s);
}



#ifdef   USE_stub_in_nt_dll_NOT_DEFINED_ManipulatorCommonInterface__Common
# undef  USE_stub_in_nt_dll
# undef  USE_stub_in_nt_dll_NOT_DEFINED_ManipulatorCommonInterface__Common
#endif
#ifdef   USE_core_stub_in_nt_dll_NOT_DEFINED_ManipulatorCommonInterface__Common
# undef  USE_core_stub_in_nt_dll
# undef  USE_core_stub_in_nt_dll_NOT_DEFINED_ManipulatorCommonInterface__Common
#endif
#ifdef   USE_dyn_stub_in_nt_dll_NOT_DEFINED_ManipulatorCommonInterface__Common
# undef  USE_dyn_stub_in_nt_dll
# undef  USE_dyn_stub_in_nt_dll_NOT_DEFINED_ManipulatorCommonInterface__Common
#endif

#endif  // __ManipulatorCommonInterface__Common_hh__

