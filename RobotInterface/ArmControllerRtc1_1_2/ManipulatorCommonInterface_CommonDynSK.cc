// This file is generated by omniidl (C++ backend) - omniORB_4_2. Do not edit.

#include "ManipulatorCommonInterface_Common.hh"

OMNI_USING_NAMESPACE(omni)

static const char* _0RL_dyn_library_version = omniORB_4_2_dyn;

static ::CORBA::TypeCode::_Tracker _0RL_tcTrack(__FILE__);

static const char* _0RL_enumMember_RTC_mAlarmType[] = { "FAULT", "WARNING", "UNKNOWN" };
static CORBA::TypeCode_ptr _0RL_tc_RTC_mAlarmType = CORBA::TypeCode::PR_enum_tc("IDL:RTC/AlarmType:1.0", "AlarmType", _0RL_enumMember_RTC_mAlarmType, 3, &_0RL_tcTrack);
#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace RTC { 
  const ::CORBA::TypeCode_ptr _tc_AlarmType = _0RL_tc_RTC_mAlarmType;
} 
#else
const ::CORBA::TypeCode_ptr RTC::_tc_AlarmType = _0RL_tc_RTC_mAlarmType;
#endif

static CORBA::PR_structMember _0RL_structmember_RTC_mAlarm[] = {
  {"code", CORBA::TypeCode::PR_ulong_tc()},
  {"type", _0RL_tc_RTC_mAlarmType},
  {"description", CORBA::TypeCode::PR_string_tc(0, &_0RL_tcTrack)}
};

#ifdef _0RL_tc_RTC_mAlarm
#  undef _0RL_tc_RTC_mAlarm
#endif
static CORBA::TypeCode_ptr _0RL_tc_RTC_mAlarm = CORBA::TypeCode::PR_struct_tc("IDL:RTC/Alarm:1.0", "Alarm", _0RL_structmember_RTC_mAlarm, 3, &_0RL_tcTrack);

#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace RTC { 
  const ::CORBA::TypeCode_ptr _tc_Alarm = _0RL_tc_RTC_mAlarm;
} 
#else
const ::CORBA::TypeCode_ptr RTC::_tc_Alarm = _0RL_tc_RTC_mAlarm;
#endif






static CORBA::TypeCode_ptr _0RL_tc_RTC_mAlarmSeq = CORBA::TypeCode::PR_alias_tc("IDL:RTC/AlarmSeq:1.0", "AlarmSeq", CORBA::TypeCode::PR_sequence_tc(0, _0RL_tc_RTC_mAlarm, &_0RL_tcTrack), &_0RL_tcTrack);


#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace RTC { 
  const ::CORBA::TypeCode_ptr _tc_AlarmSeq = _0RL_tc_RTC_mAlarmSeq;
} 
#else
const ::CORBA::TypeCode_ptr RTC::_tc_AlarmSeq = _0RL_tc_RTC_mAlarmSeq;
#endif

static CORBA::PR_structMember _0RL_structmember_RTC_mLimitValue[] = {
  {"upper", CORBA::TypeCode::PR_double_tc()},
  {"lower", CORBA::TypeCode::PR_double_tc()}
};

#ifdef _0RL_tc_RTC_mLimitValue
#  undef _0RL_tc_RTC_mLimitValue
#endif
static CORBA::TypeCode_ptr _0RL_tc_RTC_mLimitValue = CORBA::TypeCode::PR_struct_tc("IDL:RTC/LimitValue:1.0", "LimitValue", _0RL_structmember_RTC_mLimitValue, 2, &_0RL_tcTrack);




static CORBA::TypeCode_ptr _0RL_tc_RTC_mLimitSeq = CORBA::TypeCode::PR_alias_tc("IDL:RTC/LimitSeq:1.0", "LimitSeq", CORBA::TypeCode::PR_sequence_tc(0, _0RL_tc_RTC_mLimitValue, &_0RL_tcTrack), &_0RL_tcTrack);


#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace RTC { 
  const ::CORBA::TypeCode_ptr _tc_LimitSeq = _0RL_tc_RTC_mLimitSeq;
} 
#else
const ::CORBA::TypeCode_ptr RTC::_tc_LimitSeq = _0RL_tc_RTC_mLimitSeq;
#endif

static CORBA::TypeCode_ptr _0RL_tc_RTC_mULONG = CORBA::TypeCode::PR_alias_tc("IDL:RTC/ULONG:1.0", "ULONG", CORBA::TypeCode::PR_ulong_tc(), &_0RL_tcTrack);


static CORBA::PR_structMember _0RL_structmember_RTC_mManipInfo[] = {
  {"manufactur", CORBA::TypeCode::PR_string_tc(0, &_0RL_tcTrack)},
  {"type", CORBA::TypeCode::PR_string_tc(0, &_0RL_tcTrack)},
  {"axisNum", _0RL_tc_RTC_mULONG},
  {"cmdCycle", _0RL_tc_RTC_mULONG},
  {"isGripper", CORBA::TypeCode::PR_boolean_tc()}
};

#ifdef _0RL_tc_RTC_mManipInfo
#  undef _0RL_tc_RTC_mManipInfo
#endif
static CORBA::TypeCode_ptr _0RL_tc_RTC_mManipInfo = CORBA::TypeCode::PR_struct_tc("IDL:RTC/ManipInfo:1.0", "ManipInfo", _0RL_structmember_RTC_mManipInfo, 5, &_0RL_tcTrack);

#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace RTC { 
  const ::CORBA::TypeCode_ptr _tc_ManipInfo = _0RL_tc_RTC_mManipInfo;
} 
#else
const ::CORBA::TypeCode_ptr RTC::_tc_ManipInfo = _0RL_tc_RTC_mManipInfo;
#endif


const CORBA::TypeCode_ptr _tc_ManipulatorCommonInterface_Common = CORBA::TypeCode::PR_interface_tc("IDL:ManipulatorCommonInterface_Common:1.0", "ManipulatorCommonInterface_Common", &_0RL_tcTrack);

static void _0RL_RTC_mAlarmType_marshal_fn(cdrStream& _s, void* _v)
{
  RTC::AlarmType* _p = (RTC::AlarmType*)_v;
  *_p >>= _s;
}
static void _0RL_RTC_mAlarmType_unmarshal_fn(cdrStream& _s, void*& _v)
{
  RTC::AlarmType* _p = (RTC::AlarmType*)_v;
  *_p <<= _s;
}

void operator<<=(::CORBA::Any& _a, RTC::AlarmType _s)
{
  _a.PR_insert(_0RL_tc_RTC_mAlarmType,
               _0RL_RTC_mAlarmType_marshal_fn,
               &_s);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, RTC::AlarmType& _s)
{
  return _a.PR_extract(_0RL_tc_RTC_mAlarmType,
                       _0RL_RTC_mAlarmType_unmarshal_fn,
                       &_s);
}

static void _0RL_RTC_mAlarm_marshal_fn(cdrStream& _s, void* _v)
{
  RTC::Alarm* _p = (RTC::Alarm*)_v;
  *_p >>= _s;
}
static void _0RL_RTC_mAlarm_unmarshal_fn(cdrStream& _s, void*& _v)
{
  RTC::Alarm* _p = new RTC::Alarm;
  *_p <<= _s;
  _v = _p;
}
static void _0RL_RTC_mAlarm_destructor_fn(void* _v)
{
  RTC::Alarm* _p = (RTC::Alarm*)_v;
  delete _p;
}

void operator<<=(::CORBA::Any& _a, const RTC::Alarm& _s)
{
  RTC::Alarm* _p = new RTC::Alarm(_s);
  _a.PR_insert(_0RL_tc_RTC_mAlarm,
               _0RL_RTC_mAlarm_marshal_fn,
               _0RL_RTC_mAlarm_destructor_fn,
               _p);
}
void operator<<=(::CORBA::Any& _a, RTC::Alarm* _sp)
{
  _a.PR_insert(_0RL_tc_RTC_mAlarm,
               _0RL_RTC_mAlarm_marshal_fn,
               _0RL_RTC_mAlarm_destructor_fn,
               _sp);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, RTC::Alarm*& _sp)
{
  return _a >>= (const RTC::Alarm*&) _sp;
}
::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, const RTC::Alarm*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_RTC_mAlarm,
                    _0RL_RTC_mAlarm_unmarshal_fn,
                    _0RL_RTC_mAlarm_marshal_fn,
                    _0RL_RTC_mAlarm_destructor_fn,
                    _v)) {
    _sp = (const RTC::Alarm*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_RTC_mAlarmSeq_marshal_fn(cdrStream& _s, void* _v)
{
  RTC::AlarmSeq* _p = (RTC::AlarmSeq*)_v;
  *_p >>= _s;
}
static void _0RL_RTC_mAlarmSeq_unmarshal_fn(cdrStream& _s, void*& _v)
{
  RTC::AlarmSeq* _p = new RTC::AlarmSeq;
  *_p <<= _s;
  _v = _p;
}
static void _0RL_RTC_mAlarmSeq_destructor_fn(void* _v)
{
  RTC::AlarmSeq* _p = (RTC::AlarmSeq*)_v;
  delete _p;
}

void operator<<=(::CORBA::Any& _a, const RTC::AlarmSeq& _s)
{
  RTC::AlarmSeq* _p = new RTC::AlarmSeq(_s);
  _a.PR_insert(_0RL_tc_RTC_mAlarmSeq,
               _0RL_RTC_mAlarmSeq_marshal_fn,
               _0RL_RTC_mAlarmSeq_destructor_fn,
               _p);
}
void operator<<=(::CORBA::Any& _a, RTC::AlarmSeq* _sp)
{
  _a.PR_insert(_0RL_tc_RTC_mAlarmSeq,
               _0RL_RTC_mAlarmSeq_marshal_fn,
               _0RL_RTC_mAlarmSeq_destructor_fn,
               _sp);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, RTC::AlarmSeq*& _sp)
{
  return _a >>= (const RTC::AlarmSeq*&) _sp;
}
::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, const RTC::AlarmSeq*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_RTC_mAlarmSeq,
                    _0RL_RTC_mAlarmSeq_unmarshal_fn,
                    _0RL_RTC_mAlarmSeq_marshal_fn,
                    _0RL_RTC_mAlarmSeq_destructor_fn,
                    _v)) {
    _sp = (const RTC::AlarmSeq*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_RTC_mLimitSeq_marshal_fn(cdrStream& _s, void* _v)
{
  RTC::LimitSeq* _p = (RTC::LimitSeq*)_v;
  *_p >>= _s;
}
static void _0RL_RTC_mLimitSeq_unmarshal_fn(cdrStream& _s, void*& _v)
{
  RTC::LimitSeq* _p = new RTC::LimitSeq;
  *_p <<= _s;
  _v = _p;
}
static void _0RL_RTC_mLimitSeq_destructor_fn(void* _v)
{
  RTC::LimitSeq* _p = (RTC::LimitSeq*)_v;
  delete _p;
}

void operator<<=(::CORBA::Any& _a, const RTC::LimitSeq& _s)
{
  RTC::LimitSeq* _p = new RTC::LimitSeq(_s);
  _a.PR_insert(_0RL_tc_RTC_mLimitSeq,
               _0RL_RTC_mLimitSeq_marshal_fn,
               _0RL_RTC_mLimitSeq_destructor_fn,
               _p);
}
void operator<<=(::CORBA::Any& _a, RTC::LimitSeq* _sp)
{
  _a.PR_insert(_0RL_tc_RTC_mLimitSeq,
               _0RL_RTC_mLimitSeq_marshal_fn,
               _0RL_RTC_mLimitSeq_destructor_fn,
               _sp);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, RTC::LimitSeq*& _sp)
{
  return _a >>= (const RTC::LimitSeq*&) _sp;
}
::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, const RTC::LimitSeq*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_RTC_mLimitSeq,
                    _0RL_RTC_mLimitSeq_unmarshal_fn,
                    _0RL_RTC_mLimitSeq_marshal_fn,
                    _0RL_RTC_mLimitSeq_destructor_fn,
                    _v)) {
    _sp = (const RTC::LimitSeq*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_RTC_mManipInfo_marshal_fn(cdrStream& _s, void* _v)
{
  RTC::ManipInfo* _p = (RTC::ManipInfo*)_v;
  *_p >>= _s;
}
static void _0RL_RTC_mManipInfo_unmarshal_fn(cdrStream& _s, void*& _v)
{
  RTC::ManipInfo* _p = new RTC::ManipInfo;
  *_p <<= _s;
  _v = _p;
}
static void _0RL_RTC_mManipInfo_destructor_fn(void* _v)
{
  RTC::ManipInfo* _p = (RTC::ManipInfo*)_v;
  delete _p;
}

void operator<<=(::CORBA::Any& _a, const RTC::ManipInfo& _s)
{
  RTC::ManipInfo* _p = new RTC::ManipInfo(_s);
  _a.PR_insert(_0RL_tc_RTC_mManipInfo,
               _0RL_RTC_mManipInfo_marshal_fn,
               _0RL_RTC_mManipInfo_destructor_fn,
               _p);
}
void operator<<=(::CORBA::Any& _a, RTC::ManipInfo* _sp)
{
  _a.PR_insert(_0RL_tc_RTC_mManipInfo,
               _0RL_RTC_mManipInfo_marshal_fn,
               _0RL_RTC_mManipInfo_destructor_fn,
               _sp);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, RTC::ManipInfo*& _sp)
{
  return _a >>= (const RTC::ManipInfo*&) _sp;
}
::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, const RTC::ManipInfo*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_RTC_mManipInfo,
                    _0RL_RTC_mManipInfo_unmarshal_fn,
                    _0RL_RTC_mManipInfo_marshal_fn,
                    _0RL_RTC_mManipInfo_destructor_fn,
                    _v)) {
    _sp = (const RTC::ManipInfo*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_ManipulatorCommonInterface__Common_marshal_fn(cdrStream& _s, void* _v)
{
  omniObjRef* _o = (omniObjRef*)_v;
  omniObjRef::_marshal(_o, _s);
}
static void _0RL_ManipulatorCommonInterface__Common_unmarshal_fn(cdrStream& _s, void*& _v)
{
  omniObjRef* _o = omniObjRef::_unMarshal(ManipulatorCommonInterface_Common::_PD_repoId, _s);
  _v = _o;
}
static void _0RL_ManipulatorCommonInterface__Common_destructor_fn(void* _v)
{
  omniObjRef* _o = (omniObjRef*)_v;
  if (_o)
    omni::releaseObjRef(_o);
}

void operator<<=(::CORBA::Any& _a, ManipulatorCommonInterface_Common_ptr _o)
{
  ManipulatorCommonInterface_Common_ptr _no = ManipulatorCommonInterface_Common::_duplicate(_o);
  _a.PR_insert(_tc_ManipulatorCommonInterface_Common,
               _0RL_ManipulatorCommonInterface__Common_marshal_fn,
               _0RL_ManipulatorCommonInterface__Common_destructor_fn,
               _no->_PR_getobj());
}
void operator<<=(::CORBA::Any& _a, ManipulatorCommonInterface_Common_ptr* _op)
{
  _a.PR_insert(_tc_ManipulatorCommonInterface_Common,
               _0RL_ManipulatorCommonInterface__Common_marshal_fn,
               _0RL_ManipulatorCommonInterface__Common_destructor_fn,
               (*_op)->_PR_getobj());
  *_op = ManipulatorCommonInterface_Common::_nil();
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, ManipulatorCommonInterface_Common_ptr& _o)
{
  void* _v;
  if (_a.PR_extract(_tc_ManipulatorCommonInterface_Common,
                    _0RL_ManipulatorCommonInterface__Common_unmarshal_fn,
                    _0RL_ManipulatorCommonInterface__Common_marshal_fn,
                    _0RL_ManipulatorCommonInterface__Common_destructor_fn,
                    _v)) {
    omniObjRef* _r = (omniObjRef*)_v;
    if (_r)
      _o = (ManipulatorCommonInterface_Common_ptr)_r->_ptrToObjRef(ManipulatorCommonInterface_Common::_PD_repoId);
    else
      _o = ManipulatorCommonInterface_Common::_nil();
    return 1;
  }
  return 0;
}

