//
//  MyData.cpp
//  test
//
//  Created by ChengJY on 14-2-25.
//  Copyright (c) 2014年 ChengJY. All rights reserved.
//
#include "MyData.h"
CMyData::CMyData():
m_iIndex(0),
m_iDataSize(0),
m_strDatamember(NULL)
{
}

CMyData::CMyData(int Index,const char* strData):
m_iIndex(Index),
m_iDataSize(0),
m_strDatamember(NULL)
{
    m_iDataSize = (int)strlen(strData);
    m_strDatamember = new char[m_iDataSize+1];
    strcpy(m_strDatamember,strData);
}

CMyData::~CMyData()
{
    if(m_strDatamember != NULL)
        delete[] m_strDatamember;
    m_strDatamember = NULL;
}

CMyData& CMyData::operator =(CMyData &SrcData)
{
    m_iIndex = SrcData.m_iIndex;
    m_iDataSize = SrcData.GetDataSize();
    m_strDatamember = new char[m_iDataSize+1];
    strcpy(m_strDatamember,SrcData.GetData());
    return *this;
}

bool CMyData::operator <(CMyData& data )
{
    return m_iIndex<data.m_iIndex;
}

bool CMyData::operator >(CMyData& data )
{ 
    return m_iIndex>data.m_iIndex; 
}