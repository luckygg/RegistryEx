#include "StdAfx.h"
#include "RegistryEx.h"

bool CRegistryEx::OnAddKey(KeyRoot Root, CString strKey, CString strSubKey)
{
	CRegKey regKey;
	HKEY Key;
	
	switch(Root)
	{
		case CLASSES_ROOT	: Key = HKEY_CLASSES_ROOT;	break;
		case CURRENT_USER	: Key = HKEY_CURRENT_USER;	break;
		case LOCAL_MACHINE	: Key = HKEY_LOCAL_MACHINE; break;
		case USERS			: Key = HKEY_USERS;			break;
		case CURRENT_CONFIG : Key = HKEY_CURRENT_CONFIG;break;
	}

	strKey += _T("\\") + strSubKey;
	
	if(regKey.Create(Key, strKey) != ERROR_SUCCESS)
		return false;

	return true;
}

bool CRegistryEx::OnDeleteKey(KeyRoot Root, CString strKey, CString strSubKey)
{
	CRegKey regKey;
	HKEY Key;

	switch(Root)
	{
		case CLASSES_ROOT	: Key = HKEY_CLASSES_ROOT;	break;
		case CURRENT_USER	: Key = HKEY_CURRENT_USER;	break;
		case LOCAL_MACHINE	: Key = HKEY_LOCAL_MACHINE; break;
		case USERS			: Key = HKEY_USERS;			break;
		case CURRENT_CONFIG : Key = HKEY_CURRENT_CONFIG;break;
	}
	
	if(regKey.Open(Key, strKey) != ERROR_SUCCESS)
		return false;

	// Key�� ������ �� ���� Ű���� ���������� �����ؾ� �Ѵ�.
	// ���� shlwapi library�� �̿��� SHDeleteKey API ��� �� ���� Ű �����Ͽ� �� ���� ���� �����ϴ�.
	if (regKey.DeleteSubKey(strSubKey) != ERROR_SUCCESS)
	{
		regKey.Close();
		return false;
	}
	
	regKey.Close();

	return true;
}

bool CRegistryEx::SetValue(KeyRoot Root, CString strKeyPath, CString strValueName, CString strValue)
{
	return WriteValue(Root, strKeyPath, strValueName, strValue);
}

bool CRegistryEx::SetValue(KeyRoot Root, CString strKeyPath, CString strValueName, double dValue)
{
	CString value=_T("");
	value.Format(_T("%.10f"),dValue);

	return WriteValue(Root, strKeyPath, strValueName, value);
}

bool CRegistryEx::SetValue(KeyRoot Root, CString strKeyPath, CString strValueName, int nValue)
{
	CString value=_T("");
	value.Format(_T("%d"),nValue);

	return WriteValue(Root, strKeyPath, strValueName, value);
}

bool CRegistryEx::GetValue(KeyRoot Root, CString strKeyPath, CString strValueName, CString &strValue)
{
	CString value=_T("");
	bool ret = ReadValue(Root, strKeyPath, strValueName, value);
	if (ret == false)
		return false;

	strValue = value;
	return true;
}

bool CRegistryEx::GetValue(KeyRoot Root, CString strKeyPath, CString strValueName, double &dValue)
{
	CString value=_T("");
	bool ret = ReadValue(Root, strKeyPath, strValueName, value);
	if (ret == false)
		return false;

	dValue = _ttof(value);
	return true;
}

bool CRegistryEx::GetValue(KeyRoot Root, CString strKeyPath, CString strValueName, int &nValue)
{
	CString value=_T("");
	bool ret = ReadValue(Root, strKeyPath, strValueName, value);
	if (ret == false)
		return false;

	nValue = _ttoi(value);
	return true;
}

bool CRegistryEx::WriteValue(KeyRoot Root, CString strKeyPath, CString strValueName, CString strValue)
{
	CRegKey regKey;
	HKEY Key;

	switch(Root)
	{
		case CLASSES_ROOT	: Key = HKEY_CLASSES_ROOT;	break;
		case CURRENT_USER	: Key = HKEY_CURRENT_USER;	break;
		case LOCAL_MACHINE	: Key = HKEY_LOCAL_MACHINE; break;
		case USERS			: Key = HKEY_USERS;			break;
		case CURRENT_CONFIG : Key = HKEY_CURRENT_CONFIG;break;
	}

	if(regKey.Open(Key, strKeyPath) != ERROR_SUCCESS)
		return false;

	if (regKey.SetStringValue(strValueName, strValue) != ERROR_SUCCESS)
		return false;

	strValue.ReleaseBuffer(); 

	regKey.Close();

	return true;
}

bool CRegistryEx::ReadValue(KeyRoot Root, CString strKeyPath, CString strValueName, CString &strValue)
{
	CRegKey regKey;
	HKEY Key;

	switch(Root)
	{
	case CLASSES_ROOT	: Key = HKEY_CLASSES_ROOT;	break;
	case CURRENT_USER	: Key = HKEY_CURRENT_USER;	break;
	case LOCAL_MACHINE	: Key = HKEY_LOCAL_MACHINE; break;
	case USERS			: Key = HKEY_USERS;			break;
	case CURRENT_CONFIG : Key = HKEY_CURRENT_CONFIG;break;
	}

	if(regKey.Open(Key, strKeyPath) != ERROR_SUCCESS)
		return false;

	// QueryStringValue�� ȣ���ϱ� ���� �׻� dwSize�� 1024�� �ʱ�ȭ����� �Ѵ�.
	DWORD dwSize = 1024;
	CString value=_T("");
	if(regKey.QueryStringValue(strValueName, value.GetBuffer(dwSize), &dwSize) != ERROR_SUCCESS)
		return false;

	strValue = value;
	value.ReleaseBuffer(); 

	regKey.Close();

	return true;
}

