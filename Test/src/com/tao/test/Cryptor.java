package com.tao.test;

public class Cryptor {
	public native static void crypt(String normal_path, String crypt_path);
	public native static void decrypt(String crypt_path, String decrypt_path);
	public native static String getMyName(String name);
	static{
		System.loadLibrary("Test");
	}
	
}
