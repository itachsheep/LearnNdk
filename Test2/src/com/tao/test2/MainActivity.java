package com.tao.test2;


import java.io.File;


import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}

	public void callJniString(View view){
		String result = Cryptor.getMyName("哈哈 ,");
		Toast.makeText(MainActivity.this, result, Toast.LENGTH_SHORT).show();
	}
	
	public void enCrypt(View view){
		File exfile = Environment.getExternalStorageDirectory();
		File file = new File(exfile, "target.jpg");
		File cryptfile = new File(exfile, "target_crypt.jpg");
		Cryptor.crypt(file.getAbsolutePath(), cryptfile.getAbsolutePath());
		Log.d("ndk", "加密完成");
	}
	
	public void deCrypt(View view){
		File exfile = Environment.getExternalStorageDirectory();
		File file = new File(exfile, "target_crypt.jpg");
		File decryptfile = new File(exfile, "target_decrypt.jpg");
		Cryptor.decrypt(file.getAbsolutePath(), decryptfile.getAbsolutePath());
		Log.d("ndk", "解密完成");
	}
	

}
