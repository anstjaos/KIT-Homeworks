package Online_bank;

import java.sql.DriverManager;
import java.sql.SQLException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public abstract class Account implements Subject {
	private static long lastAccountNum = 0;
	protected String accountNum;
	protected String ownerId;
	protected int balance;
	protected String createDate;
	protected int type;
	
	private ArrayList<Observer> observers;
	
	public Account() {}
	
	public Account(String ownerId, int money, int type) {
		accountNum = String.format("%010d", ++lastAccountNum);
		this.ownerId = ownerId;
		balance = money;
		
		DateFormat dateFormat = new SimpleDateFormat("yyyyMMdd");
		Calendar cal = Calendar.getInstance();
		createDate = dateFormat.format(cal.getTime());
		
		observers = new ArrayList<Observer>();
		this.type = type;
	}
	
	public Account(String accountNum, String ownerId, int balance, String createDate, int type) {
		this.accountNum = accountNum;
		this.ownerId = ownerId;
		this.balance = balance;
		this.createDate = createDate;
		this.type = type;
		
		observers = new ArrayList<Observer>();
	}
	
	public void initLastAccountNum() {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "select * from account order by accountNum desc limit 1;";
		
			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			ResultSet rs = pstmt.executeQuery();
			 
            if (rs.next()) {
            	lastAccountNum = rs.getInt("accountNum");
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
	
	public String getAccountNum() {
		return accountNum;
	}
	
	public String getOwnerId() {
		return ownerId;
	}
	
	public int getBalance() {
		return balance;
	}
	
	public String getCreateDate() {
		return createDate;
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
	
	public abstract void registerAccount();
	
	public boolean removeAccount() {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "delete from account where accountNum = ?;";
		
			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setString(1, accountNum);
			if(pstmt.executeUpdate() == 0) return false;
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
	
	public void updateAccount() {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "update account set balance=? where accountNum = ?;";

			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setInt(1, balance);
			pstmt.setString(2, accountNum);

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
	
	public Account findAccount(String accountNum) {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
		Account a = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "select * from account where accountNum = ?";

			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setString(1, accountNum);
			ResultSet rs = pstmt.executeQuery();
			 
            if (rs.next()) {
            	String ownerId = rs.getString("ownerId");
            	int balance = rs.getInt("balance");
            	String createDate = rs.getString("createDate");
            	int type = rs.getInt("type");
            	int creditLimit = rs.getInt("creditLimit");
            	
            	if(type == 0) a = new FreeAccount(accountNum, ownerId, balance, createDate, type);
            	else if(type == 1) a = new MinusAccount(accountNum, ownerId, balance, createDate, type, creditLimit);
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
        return a;
	}
	
	public ArrayList<Account> selectAccounts(String ownerId) {
		String userId = "root";
		String password = "anstj0177";
		ArrayList<Account> al = new ArrayList<Account>();
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "select * from account where ownerId = ?;";
		
			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setString(1, ownerId);
			ResultSet re = pstmt.executeQuery();
			 
            while (re.next()) {
            	Account a = null;
            	String accountNum = re.getString("accountNum");
            	int balance = re.getInt("balance");
            	String createDate = re.getString("createDate");
            	int type = re.getInt("type");
            	int creditLimit = re.getInt("creditLimit");
            	
            	if(type == 0) a = new FreeAccount(accountNum, ownerId, balance, createDate, type);
            	else if(type == 1) a = new MinusAccount(accountNum, ownerId, balance, createDate, type, creditLimit);
             
                al.add(a);
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
        return al;
	}
	
	public void deposit(int money) {
		balance += money;
	}
	
	public abstract boolean withdraw(int money);
}
