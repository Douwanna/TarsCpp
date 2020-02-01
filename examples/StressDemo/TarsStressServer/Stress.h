// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 1.4.0.
// **********************************************************************

#ifndef __STRESS_H_
#define __STRESS_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
#include "tup/TarsJson.h"
using namespace std;
#include "servant/ServantProxy.h"
#include "servant/Servant.h"


namespace Test
{

    /* callback of async proxy for client */
    class StressPrxCallback: public tars::ServantProxyCallback
    {
    public:
        virtual ~StressPrxCallback(){}
        virtual void callback_test(tars::Int32 ret)
        { throw std::runtime_error("callback_test() override incorrect."); }
        virtual void callback_test_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_test_exception() override incorrect."); }

        virtual void callback_testStr(tars::Int32 ret,  const std::string& sOut)
        { throw std::runtime_error("callback_testStr() override incorrect."); }
        virtual void callback_testStr_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_testStr_exception() override incorrect."); }

    public:
        virtual const map<std::string, std::string> & getResponseContext() const
        {
            CallbackThreadData * pCbtd = CallbackThreadData::getData();
            assert(pCbtd != NULL);

            if(!pCbtd->getContextValid())
            {
                throw TC_Exception("cann't get response context");
            }
            return pCbtd->getResponseContext();
        }

    public:
        virtual int onDispatchException(const tars::RequestPacket &request, const tars::ResponsePacket &response)
        {
            static ::std::string __Stress_all[]=
            {
                "test",
                "testStr"
            };
            pair<string*, string*> r = equal_range(__Stress_all, __Stress_all+2, request.sFuncName);
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Stress_all)
            {
                case 0:
                {
                        callback_test_exception(response.iRet);

                        return response.iRet;

                }
                case 1:
                {
                        callback_testStr_exception(response.iRet);

                        return response.iRet;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

        virtual int onDispatchResponse(const tars::RequestPacket &request, const tars::ResponsePacket &response)
        {
            static ::std::string __Stress_all[]=
            {
                "test",
                "testStr"
            };
            pair<string*, string*> r = equal_range(__Stress_all, __Stress_all+2, request.sFuncName);
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Stress_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(response.sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(response.context);

                    callback_test(_ret);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(response.sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    std::string sOut;
                    _is.read(sOut, 2, true);
                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(response.context);

                    callback_testStr(_ret, sOut);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<StressPrxCallback> StressPrxCallbackPtr;

    /* callback of coroutine async proxy for client */
    class StressCoroPrxCallback: public StressPrxCallback
    {
    public:
        virtual ~StressCoroPrxCallback(){}
    public:
        virtual const map<std::string, std::string> & getResponseContext() const { return _mRspContext; }

        virtual void setResponseContext(const map<std::string, std::string> &mContext) { _mRspContext = mContext; }

    public:
        virtual int onDispatchResponse(const tars::RequestPacket &request, const tars::ResponsePacket &response)
        {
            static ::std::string __Stress_all[]=
            {
                "test",
                "testStr"
            };

            pair<string*, string*> r = equal_range(__Stress_all, __Stress_all+2, request.sFuncName);
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Stress_all)
            {
                case 0:
                {
                        callback_test_exception(response.iRet);

                        return response.iRet;

                }
                case 1:
                {
                        callback_testStr_exception(response.iRet);

                        return response.iRet;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

        virtual int onDispatchException(const tars::RequestPacket &request, const tars::ResponsePacket &response)
        {
            static ::std::string __Stress_all[]=
            {
                "test",
                "testStr"
            };

            pair<string*, string*> r = equal_range(__Stress_all, __Stress_all+2, request.sFuncName);
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Stress_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(response.sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        setResponseContext(response.context);

                        callback_test(_ret);

                    }
                    catch(std::exception &ex)
                    {
                        callback_test_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_test_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(response.sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        std::string sOut;
                        _is.read(sOut, 2, true);
                        setResponseContext(response.context);

                        callback_testStr(_ret, sOut);

                    }
                    catch(std::exception &ex)
                    {
                        callback_testStr_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_testStr_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    protected:
        map<std::string, std::string> _mRspContext;
    };
    typedef tars::TC_AutoPtr<StressCoroPrxCallback> StressCoroPrxCallbackPtr;

    /* proxy for client */
    class StressProxy : public tars::ServantProxy
    {
    public:
        typedef map<string, string> TARS_CONTEXT;
        tars::Int32 test(const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            std::map<string, string> _mStatus;
            shared_ptr<tars::ResponsePacket> rep = tars_invoke(tars::TARSNORMAL,"test", _os, context, _mStatus);
            if(pResponseContext)
            {
                pResponseContext->swap(rep->context);
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep->sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            return _ret;
        }

        void async_test(StressPrxCallbackPtr callback,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"test", _os, context, _mStatus, callback);
        }
        
        void coro_test(StressCoroPrxCallbackPtr callback,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"test", _os, context, _mStatus, callback, true);
        }

        tars::Int32 testStr(const std::string & sIn,std::string &sOut,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(sIn, 1);
            _os.write(sOut, 2);
            std::map<string, string> _mStatus;
            shared_ptr<tars::ResponsePacket> rep = tars_invoke(tars::TARSNORMAL,"testStr", _os, context, _mStatus);
            if(pResponseContext)
            {
                pResponseContext->swap(rep->context);
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep->sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            _is.read(sOut, 2, true);
            return _ret;
        }

        void async_testStr(StressPrxCallbackPtr callback,const std::string &sIn,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(sIn, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"testStr", _os, context, _mStatus, callback);
        }
        
        void coro_testStr(StressCoroPrxCallbackPtr callback,const std::string &sIn,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(sIn, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"testStr", _os, context, _mStatus, callback, true);
        }

        StressProxy* tars_hash(int64_t key)
        {
            return (StressProxy*)ServantProxy::tars_hash(key);
        }

        StressProxy* tars_consistent_hash(int64_t key)
        {
            return (StressProxy*)ServantProxy::tars_consistent_hash(key);
        }

        StressProxy* tars_set_timeout(int msecond)
        {
            return (StressProxy*)ServantProxy::tars_set_timeout(msecond);
        }

        static const char* tars_prxname() { return "StressProxy"; }
    };
    typedef tars::TC_AutoPtr<StressProxy> StressPrx;

    /* servant for server */
    class Stress : public tars::Servant
    {
    public:
        virtual ~Stress(){}
        virtual tars::Int32 test(tars::TarsCurrentPtr current) = 0;
        static void async_response_test(tars::TarsCurrentPtr current, tars::Int32 _ret)
        {
            if (current->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                tarsAttr.setVersion(current->getRequestVersion());
                tarsAttr.put("", _ret);

                vector<char> sTupResponseBuffer;
                tarsAttr.encode(sTupResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
            }
        }

        virtual tars::Int32 testStr(const std::string & sIn,std::string &sOut,tars::TarsCurrentPtr current) = 0;
        static void async_response_testStr(tars::TarsCurrentPtr current, tars::Int32 _ret, const std::string &sOut)
        {
            if (current->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                tarsAttr.setVersion(current->getRequestVersion());
                tarsAttr.put("", _ret);
                tarsAttr.put("sOut", sOut);

                vector<char> sTupResponseBuffer;
                tarsAttr.encode(sTupResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                _os.write(sOut, 2);

                current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
            }
        }

    public:
        int onDispatch(tars::TarsCurrentPtr _current, vector<char> &_sResponseBuffer)
        {
            static ::std::string __Test__Stress_all[]=
            {
                "test",
                "testStr"
            };

            pair<string*, string*> r = equal_range(__Test__Stress_all, __Test__Stress_all+2, _current->getFuncName());
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Test__Stress_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                    }
                    else
                    {
                    }
                    tars::Int32 _ret = test(_current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION )
                        {
                            UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                            tarsAttr.setVersion(_current->getRequestVersion());
                            tarsAttr.put("", _ret);
                            tarsAttr.encode(_sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriterVector> _os;
                            _os.write(_ret, 0);
                            _os.swap(_sResponseBuffer);
                        }
                    }
                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    std::string sIn;
                    std::string sOut;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                        tarsAttr.get("sIn", sIn);
                        tarsAttr.getByDefault("sOut", sOut, sOut);
                    }
                    else
                    {
                        _is.read(sIn, 1, true);
                        _is.read(sOut, 2, false);
                    }
                    tars::Int32 _ret = testStr(sIn,sOut, _current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION )
                        {
                            UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                            tarsAttr.setVersion(_current->getRequestVersion());
                            tarsAttr.put("", _ret);
                            tarsAttr.put("sOut", sOut);
                            tarsAttr.encode(_sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriterVector> _os;
                            _os.write(_ret, 0);
                            _os.write(sOut, 2);
                            _os.swap(_sResponseBuffer);
                        }
                    }
                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }
    };


}



#endif
