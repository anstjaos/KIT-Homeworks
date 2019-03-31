package Online_bank;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class User implements Subject {
	private String userId;
	private String password;
	private String address;
	private String phoneNum;
	private int type;
	
	private ArrayList<Observer> observers;
	
	public User(String userId, String password) {
		this.userId = userId;
		this.password = password;
	}
	
	public User(String userId, String password, String address, String phoneNum, int type) {
		this.userId = userId;
		this.password = password;
		this.address = address;
		this.phoneNum = phoneNum;
		this.type = type;
		
		observers = new ArrayList<Observer>();
	}
	
	public String getUserId() {
		return userId;
	}
	
	public String getPassword() {
		return password;
	}
	
	public String getAddress() {
		return address;
	}
	
	public String getPhoneNum() {
		return phoneNum;
	}
	
	public int getType() {
		return type;
	}
	
	public void setId(String uid) {
		userId = uid;
	}
	
	public void setPassword(String pwd) {
		password = pwd;
	}
	
	public void setAddress(String address) {
		this.address = address;
	}
	
	public void setPhoneNum(String phoneNum) {
		this.phoneNum = phoneNum;
	}
	
	public void setType(int type) {
		this.type = type;
	}
	
	public void registerObserver(Observer o) {
		observers.add(o);
	}
	
	public void removeObserver(Observer o) {
		observers.remove(o);
	}
	
	public void notifyObservers() {
		for(Observer o : observers) {
			o.update();
		}
	}
	
	public void registerUser() {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "insert into user values(?,?,?,?,?);";
		
			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setString(1, this.userId);
			pstmt.setString(2, this.password);
			pstmt.setString(3, address);
			pstmt.setString(4, phoneNum);
			pstmt.setInt(5, type);
			pstmt.executeUpdate();
		} catch (SQLException se1) {
            se1.printStackTrace();
        } catch (Exception ex) {
            ex.printStackTrace();
        } finally {
            try {
                if (pstmt != null) pstmt.close();
            } catch (SQLException se2) {
            }
            try {
                if (connection != null)
                    connection.close();
            } catch (SQLException se) {
                se.printStackTrace();
            }
        }	
	}
	
	public void updateUser() {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "update user set password=?, address=?, phoneNum=? where userId = ?;";

			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setString(1, this.password);
			pstmt.setString(2, address);
			pstmt.setString(3, phoneNum);
			pstmt.setString(4, this.userId);
			
			pstmt.executeUpdate();
		} catch (SQLException se1) {
            se1.printStackTrace();
        } catch (Exception ex) {
            ex.printStackTrace();
        } finally {
            try {
                if (pstmt != null) pstmt.close();
            } catch (SQLException se2) {
            }
            try {
                if (connection != null)
                    connection.close();
            } catch (SQLException se) {
                se.printStackTrace();
            }
        }
	}
	
	public boolean existId() {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
	
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "select * from user where userId = ?";

			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setString(1, this.userId);
			ResultSet rs = pstmt.executeQuery();
			 
            if (rs.next()) {
            	return true;
            }
            else return false;
		} catch (SQLException se1) {
            se1.printStackTrace();
        } catch (Exception ex) {
            ex.printStackTrace();
        } finally {
            try {
                if (pstmt != null) pstmt.close();
            } catch (SQLException se2) {
            }
            try {
                if (connection != null)
                    connection.close();
            } catch (SQLException se) {
                se.printStackTrace();
            }
        }
        return true;
	}
	
	public void findUser() {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
	
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "select * from user where userId = ?";

			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setString(1, this.userId);
			ResultSet rs = pstmt.executeQuery();
			 
            if (rs.next()) {
            	this.password = rs.getString("password");
            	this.address = rs.getString("address");
            	this.phoneNum = rs.getString("phoneNum");
            	this.type = rs.getInt("type");
            }
		} catch (SQLException se1) {
            se1.printStackTrace();
        } catch (Exception ex) {
            ex.printStackTrace();
        } finally {
            try {
                if (pstmt != null) pstmt.close();
            } catch (SQLException se2) {
            }
            try {
                if (connection != null)
                    connection.close();
            } catch (SQLException se) {
                se.printStackTrace();
            }
        }
	}
	
	public boolean loginUser() {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "select * from user where userId = ? and password = ?";

			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setString(1, this.userId);
			pstmt.setString(2, this.password);
			
			ResultSet rs = pstmt.executeQuery();
			
            if (rs.next()) {
            	this.address = rs.getString("address");
            	this.phoneNum = rs.getString("phoneNum");
            	this.type = rs.getInt("type");
            }
            else return false;
		} catch (SQLException se1) {
            se1.printStackTrace();
        } catch (Exception ex) {
            ex.printStackTrace();
        } finally {
            try {
                if (pstmt != null) pstmt.close();
            } catch (SQLException se2) {
            }
            try {
                if (connection != null)
                    connection.close();
            } catch (SQLException se) {
                se.printStackTrace();
            }
        }
        
		return true;
	}
}
