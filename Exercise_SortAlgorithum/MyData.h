//
//  MyData.h
//  test
//
//  Created by ChengJY on 14-2-25.
//  Copyright (c) 2014年 ChengJY. All rights reserved.
//

#ifndef __test__MyData__
#define __test__MyData__

#include <iostream>

class CMyData
{
public:
    CMyData(int Index,const char* strData);
    CMyData();
    virtual ~CMyData();
    
    int m_iIndex;
    int GetDataSize(){ return m_iDataSize; };
    const char* GetData(){ return m_strDatamember; };
    //这里重载了操作符：
    CMyData& operator = (CMyData &SrcData);
    bool operator < (CMyData& data );
    bool operator > (CMyData& data );
    
private:
    char* m_strDatamember;
    int m_iDataSize;
};

#endif /* defined(__test__MyData__) */
