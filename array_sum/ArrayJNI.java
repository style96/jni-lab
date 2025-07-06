package com.example.jni;

public class ArrayJNI {
    static {
        System.loadLibrary("array_jni");
    }

    public native int sumArray(int[] values);

    public static void main(String[] args) {
        ArrayJNI jni = new ArrayJNI();
        int[] sayilar = {10, 20, 30};
        int toplam = jni.sumArray(sayilar);
        System.out.println("Toplam: " + toplam);
    }
}
