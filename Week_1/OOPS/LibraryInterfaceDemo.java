public class LibraryInterfaceDemo {
    public static void main(String[] args) {
        KidUser child1 = new KidUser(10, "Kids");
        child1.registerAccount();
        child1.requestBook();

        KidUser child2 = new KidUser(18, "Fiction");
        child2.registerAccount();
        child2.requestBook();

        AdultUser member1 = new AdultUser(5, "Kids");
        member1.registerAccount();
        member1.requestBook();

        AdultUser member2 = new AdultUser(23, "Fiction");
        member2.registerAccount();
        member2.requestBook();
    }
}
