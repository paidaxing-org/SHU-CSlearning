public class UndergraduateException extends Exception{
    String message;
    public UndergraduateException(String Message){
        this.message = Message;
    }
    public String warnMess() {
        return message;
    }
}
