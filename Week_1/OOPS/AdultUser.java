class AdultUser implements LibraryUser {
    int age;
    String bookType;

    AdultUser(int age, String bookType) {
        this.age = age;
        this.bookType = bookType;
    }

    public void registerAccount() {
        if (age > 12)
            System.out.println("You have successfully registered under Adult Account");
        else
            System.out.println("Sorry, Age must be greater than 12 years to register as an adult");
    }

    public void requestBook() {
        if (bookType.equalsIgnoreCase("Fiction"))
            System.out.println("Book Issued successfully, please return the book within 7 days");
        else
            System.out.println("Oops, you are allowed to only take adult Fiction books");
    }
}
