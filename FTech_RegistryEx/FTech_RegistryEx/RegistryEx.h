//----------------------------------------------------------
// RegistryEx Class
//----------------------------------------------------------
// Programmed by William Kim
//----------------------------------------------------------
// Last Update : 2017-04-24 09:19
// Modified by William Kim
//----------------------------------------------------------
// shlwapi.h, shlwapi.lib Library�� ����Ͽ� SHDeleteKey�� ���� API�� ����ص� �ȴ�.
// �ڼ��� ������ http://mindgear.tistory.com/242 ����.
//----------------------------------------------------------
#pragma once

enum KeyRoot { CLASSES_ROOT=0, CURRENT_USER, LOCAL_MACHINE, USERS, CURRENT_CONFIG };
class CRegistryEx
{
public :
	static bool OnAddKey(KeyRoot Root, CString strKey, CString strSubKey);
	static bool OnDeleteKey(KeyRoot Root, CString strKey, CString strSubKey);
	static bool SetValue(KeyRoot Root, CString strKeyPath, CString strValueName, CString strValue);
	static bool SetValue(KeyRoot Root, CString strKeyPath, CString strValueName, int nValue);
	static bool SetValue(KeyRoot Root, CString strKeyPath, CString strValueName, double dValue);
	static bool GetValue(KeyRoot Root, CString strKeyPath, CString strValueName, CString &strValue);
	static bool GetValue(KeyRoot Root, CString strKeyPath, CString strValueName, int &nValue);
	static bool GetValue(KeyRoot Root, CString strKeyPath, CString strValueName, double &dValue);

private :
	static bool WriteValue(KeyRoot Root, CString strKeyPath, CString strValueName, CString strValue);
	static bool ReadValue(KeyRoot Root, CString strKeyPath, CString strValueName, CString &strValue);
};

