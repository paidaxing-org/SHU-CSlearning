import java.util.Date;

public abstract class Student {
    String name;
    char gender;
    Date birthDay;
    String school;
    String stuId;
    String category;
    double[] score;
    boolean status;

    public void setInformation(String name,char gender,Date birthDay,String school,String stuId,String category,double[] score,boolean status) {
        this.name = name;
        this.gender = gender;
        this.birthDay = birthDay;
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
        return birthDay;
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

    public abstract String getDegree();
    public abstract boolean getPass();
    public abstract double computeAverage();
}