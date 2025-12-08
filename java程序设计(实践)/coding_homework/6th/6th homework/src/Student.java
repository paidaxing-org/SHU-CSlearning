import java.time.LocalDate;
import java.util.Date;

abstract class Student {
    String name;
    char gender;
    Date birthday;
    String school;
    String stuId;
    String category;
    double[] score;
    boolean status;
    public abstract String getDegree();
    public void setInformation(String name, char gender, Date birthDay, String school, String stuId, String category, double[] score, boolean status) {
        this.name = name;
        this.gender = gender;
        this.birthday = birthDay;
        this.school = school;
        this.stuId = stuId;
        this.category = category;
        this.score = score;
        this.status = status;
    }
    public String getName(){
        return name;
    }
    public char getGender(){
        return gender;
    }
    public Date getBirthDay(){
        return birthday;
    }
    public String getSchool(){
        return school;
    }
    public String getStuId(){
        return stuId;
    }
    public String getCategory(){
        return category;
    }

}