public class MasterException extends Exception {
        String message;
        public MasterException(String Message){
            this.message = Message;
        }
        public String warnMess() {
            return message;
        }
}
