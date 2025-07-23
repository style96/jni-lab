package stringexchange;

public class StringJNI {
    static {
        System.loadLibrary("string_jni");
    }

    // Native method declaration
    public native String processString(String input);

    public static void main(String[] args) {
        StringJNI jni = new StringJNI();
        String result = jni.processString("Merhaba");
        System.out.println("Native'den gelen cevap: " + result);
    }
}
