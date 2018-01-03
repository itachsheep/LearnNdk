
#include "com_tao_test2_Cryptor.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* password = "123456";
JNIEXPORT void JNICALL Java_com_tao_test2_Cryptor_crypt
  (JNIEnv *env, jclass jcls, jstring normal_path_jstr, jstring crypt_path_jstr){
	//jstr תΪ char*
	const char* normal_path = env->GetStringUTFChars(normal_path_jstr,JNI_FALSE);
	const char* crypt_path = env->GetStringUTFChars(crypt_path_jstr,JNI_FALSE);
	//���ļ�
	FILE* normal_fp = fopen(normal_path,"rb");
	FILE* crypt_fp = fopen(crypt_path,"wb");

	int ch;
	int i = 0;
	int pwd_len = strlen(password);
	while((ch = fgetc(normal_fp)) != EOF){
		fputc(ch ^ password[i % pwd_len],crypt_fp);
		i++;
	}
	fclose(crypt_fp);
	fclose(normal_fp);
}

JNIEXPORT void JNICALL Java_com_tao_test2_Cryptor_decrypt
  (JNIEnv *env, jclass jcls, jstring crypt_path_jstr, jstring decrypt_path_jstr){
	const char* crypt_path = env->GetStringUTFChars(crypt_path_jstr,JNI_FALSE);
	const char* decrypt_path = env->GetStringUTFChars(decrypt_path_jstr,JNI_FALSE);
	//
	FILE *normal_fp = fopen(crypt_path, "rb");
	FILE *crypt_fp = fopen(decrypt_path, "wb");
	//һ�ζ�ȡһ���ַ�
	int ch;
	int i = 0; //ѭ��ʹ�������е���ĸ�����������
	int pwd_len = strlen(password); //����ĳ���
	while ((ch = fgetc(normal_fp)) != EOF){ //End of File
		//д�루������㣩
		fputc(ch ^ password[i % pwd_len], crypt_fp);
		i++;
	}
	//�ر�
	fclose(crypt_fp);
	fclose(normal_fp);
}

JNIEXPORT jstring JNICALL Java_com_tao_test2_Cryptor_getMyName
  (JNIEnv *env, jclass jcls, jstring name_jstr){
	const char* str1 = env->GetStringUTFChars(name_jstr,JNI_FALSE);
	char* str2 = " this is from jni !!!";
	char toget[60];
	strcpy(toget,str1);
	strcat(toget,str2);
	jstring res = env->NewStringUTF(toget);
	return res;
}


