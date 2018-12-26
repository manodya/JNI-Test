package com.mub.app;

public class HelloJNI {

    static {
        System.loadLibrary("hello"); // Load native library hello.dll (Windows) or libhello.so (Unixes)
        //  at runtime
        // This library contains a native method called sayHello()
    }
    private native void sayHello(String name);
    private native int incrementNumber(int x);


    public static void main(String[] args) {
        HelloJNI helloJNI = new HelloJNI();
        System.out.println(helloJNI.incrementNumber(5));
        helloJNI.sayHello("Ann");


    }

}
