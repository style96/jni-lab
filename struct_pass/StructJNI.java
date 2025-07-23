package structpass;

public class StructJNI {
    static {
        System.loadLibrary("struct_jni");
    }

    public native void printPerson(Person person);

    public static void main(String[] args) {
        Person p = new Person("Halil", 28);
        new StructJNI().printPerson(p);
    }
}
