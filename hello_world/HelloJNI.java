package hello_world;

public class HelloJNI {
    static {
        System.loadLibrary("native");
    }
    public static void main(String[] args) {
        new HelloJNI().sayHello();
    }

    //Declare a native method sayHello() that receives no arguments and returns void
    private native void sayHello();
}