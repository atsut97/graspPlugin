# Python stubs generated by omniidl from ManipulatorCommonInterface_DataTypes.idl

import omniORB, _omnipy
from omniORB import CORBA, PortableServer
_0_CORBA = CORBA

_omnipy.checkVersion(3,0, __file__)

# #include "BasicDataType.idl"
import BasicDataType_idl
_0_RTC = omniORB.openModule("RTC")
_0_RTC__POA = omniORB.openModule("RTC__POA")

#
# Start of module "RTC"
#
__name__ = "RTC"
_0_RTC = omniORB.openModule("RTC", r"ManipulatorCommonInterface_DataTypes.idl")
_0_RTC__POA = omniORB.openModule("RTC__POA", r"ManipulatorCommonInterface_DataTypes.idl")


# typedef ... DoubleSeq
class DoubleSeq:
    _NP_RepositoryId = "IDL:RTC/DoubleSeq:1.0"
    def __init__(self, *args, **kw):
        raise RuntimeError("Cannot construct objects of this type.")
_0_RTC.DoubleSeq = DoubleSeq
_0_RTC._d_DoubleSeq  = (omniORB.tcInternal.tv_sequence, omniORB.tcInternal.tv_double, 0)
_0_RTC._ad_DoubleSeq = (omniORB.tcInternal.tv_alias, DoubleSeq._NP_RepositoryId, "DoubleSeq", (omniORB.tcInternal.tv_sequence, omniORB.tcInternal.tv_double, 0))
_0_RTC._tc_DoubleSeq = omniORB.tcInternal.createTypeCode(_0_RTC._ad_DoubleSeq)
omniORB.registerType(DoubleSeq._NP_RepositoryId, _0_RTC._ad_DoubleSeq, _0_RTC._tc_DoubleSeq)
del DoubleSeq

# typedef ... JointPos
class JointPos:
    _NP_RepositoryId = "IDL:RTC/JointPos:1.0"
    def __init__(self, *args, **kw):
        raise RuntimeError("Cannot construct objects of this type.")
_0_RTC.JointPos = JointPos
_0_RTC._d_JointPos  = (omniORB.tcInternal.tv_sequence, omniORB.tcInternal.tv_double, 0)
_0_RTC._ad_JointPos = (omniORB.tcInternal.tv_alias, JointPos._NP_RepositoryId, "JointPos", (omniORB.tcInternal.tv_sequence, omniORB.tcInternal.tv_double, 0))
_0_RTC._tc_JointPos = omniORB.tcInternal.createTypeCode(_0_RTC._ad_JointPos)
omniORB.registerType(JointPos._NP_RepositoryId, _0_RTC._ad_JointPos, _0_RTC._tc_JointPos)
del JointPos

# struct LimitValue
_0_RTC.LimitValue = omniORB.newEmptyClass()
class LimitValue (omniORB.StructBase):
    _NP_RepositoryId = "IDL:RTC/LimitValue:1.0"

    def __init__(self, upper, lower):
        self.upper = upper
        self.lower = lower

_0_RTC.LimitValue = LimitValue
_0_RTC._d_LimitValue  = (omniORB.tcInternal.tv_struct, LimitValue, LimitValue._NP_RepositoryId, "LimitValue", "upper", omniORB.tcInternal.tv_double, "lower", omniORB.tcInternal.tv_double)
_0_RTC._tc_LimitValue = omniORB.tcInternal.createTypeCode(_0_RTC._d_LimitValue)
omniORB.registerType(LimitValue._NP_RepositoryId, _0_RTC._d_LimitValue, _0_RTC._tc_LimitValue)
del LimitValue

# struct RETURN_ID
_0_RTC.RETURN_ID = omniORB.newEmptyClass()
class RETURN_ID (omniORB.StructBase):
    _NP_RepositoryId = "IDL:RTC/RETURN_ID:1.0"

    def __init__(self, id, comment):
        self.id = id
        self.comment = comment

_0_RTC.RETURN_ID = RETURN_ID
_0_RTC._d_RETURN_ID  = (omniORB.tcInternal.tv_struct, RETURN_ID, RETURN_ID._NP_RepositoryId, "RETURN_ID", "id", omniORB.tcInternal.tv_long, "comment", (omniORB.tcInternal.tv_string,0))
_0_RTC._tc_RETURN_ID = omniORB.tcInternal.createTypeCode(_0_RTC._d_RETURN_ID)
omniORB.registerType(RETURN_ID._NP_RepositoryId, _0_RTC._d_RETURN_ID, _0_RTC._tc_RETURN_ID)
del RETURN_ID

# struct TimedJointPos
_0_RTC.TimedJointPos = omniORB.newEmptyClass()
class TimedJointPos (omniORB.StructBase):
    _NP_RepositoryId = "IDL:RTC/TimedJointPos:1.0"

    def __init__(self, tm, pos):
        self.tm = tm
        self.pos = pos

_0_RTC.TimedJointPos = TimedJointPos
_0_RTC._d_TimedJointPos  = (omniORB.tcInternal.tv_struct, TimedJointPos, TimedJointPos._NP_RepositoryId, "TimedJointPos", "tm", omniORB.typeMapping["IDL:RTC/Time:1.0"], "pos", omniORB.typeMapping["IDL:RTC/JointPos:1.0"])
_0_RTC._tc_TimedJointPos = omniORB.tcInternal.createTypeCode(_0_RTC._d_TimedJointPos)
omniORB.registerType(TimedJointPos._NP_RepositoryId, _0_RTC._d_TimedJointPos, _0_RTC._tc_TimedJointPos)
del TimedJointPos

# typedef ... ULONG
class ULONG:
    _NP_RepositoryId = "IDL:RTC/ULONG:1.0"
    def __init__(self, *args, **kw):
        raise RuntimeError("Cannot construct objects of this type.")
_0_RTC.ULONG = ULONG
_0_RTC._d_ULONG  = omniORB.tcInternal.tv_ulong
_0_RTC._ad_ULONG = (omniORB.tcInternal.tv_alias, ULONG._NP_RepositoryId, "ULONG", omniORB.tcInternal.tv_ulong)
_0_RTC._tc_ULONG = omniORB.tcInternal.createTypeCode(_0_RTC._ad_ULONG)
omniORB.registerType(ULONG._NP_RepositoryId, _0_RTC._ad_ULONG, _0_RTC._tc_ULONG)
del ULONG

#
# End of module "RTC"
#
__name__ = "ManipulatorCommonInterface_DataTypes_idl"

_exported_modules = ( "RTC", )

# The end.
