// This file is generated by omniidl (C++ backend) - omniORB_4_2. Do not edit.

#include "HiroNX.hh"

OMNI_USING_NAMESPACE(omni)

static const char* _0RL_dyn_library_version = omniORB_4_2_dyn;

static ::CORBA::TypeCode::_Tracker _0RL_tcTrack(__FILE__);

const CORBA::TypeCode_ptr _tc_HiroNX = CORBA::TypeCode::PR_interface_tc("IDL:HiroNX:1.0", "HiroNX", &_0RL_tcTrack);

static void _0RL_HiroNX_marshal_fn(cdrStream& _s, void* _v)
{
  omniObjRef* _o = (omniObjRef*)_v;
  omniObjRef::_marshal(_o, _s);
}
static void _0RL_HiroNX_unmarshal_fn(cdrStream& _s, void*& _v)
{
  omniObjRef* _o = omniObjRef::_unMarshal(HiroNX::_PD_repoId, _s);
  _v = _o;
}
static void _0RL_HiroNX_destructor_fn(void* _v)
{
  omniObjRef* _o = (omniObjRef*)_v;
  if (_o)
    omni::releaseObjRef(_o);
}

void operator<<=(::CORBA::Any& _a, HiroNX_ptr _o)
{
  HiroNX_ptr _no = HiroNX::_duplicate(_o);
  _a.PR_insert(_tc_HiroNX,
               _0RL_HiroNX_marshal_fn,
               _0RL_HiroNX_destructor_fn,
               _no->_PR_getobj());
}
void operator<<=(::CORBA::Any& _a, HiroNX_ptr* _op)
{
  _a.PR_insert(_tc_HiroNX,
               _0RL_HiroNX_marshal_fn,
               _0RL_HiroNX_destructor_fn,
               (*_op)->_PR_getobj());
  *_op = HiroNX::_nil();
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, HiroNX_ptr& _o)
{
  void* _v;
  if (_a.PR_extract(_tc_HiroNX,
                    _0RL_HiroNX_unmarshal_fn,
                    _0RL_HiroNX_marshal_fn,
                    _0RL_HiroNX_destructor_fn,
                    _v)) {
    omniObjRef* _r = (omniObjRef*)_v;
    if (_r)
      _o = (HiroNX_ptr)_r->_ptrToObjRef(HiroNX::_PD_repoId);
    else
      _o = HiroNX::_nil();
    return 1;
  }
  return 0;
}

