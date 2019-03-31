package Online_bank;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;

public class Transaction {
	private static int lastTransactionNum = 0;
	
	private int transactionNum;
	private String accountNum;
	private String transactionDate;
	private int type; 	// 0: 입금, 1: 출금, 2: 계좌이체
	private int money;
	private String targetAccountNum;
	
	public Transaction() {}
	
	public Transaction(String accountNum, int type, int money) {
		transactionNum = ++lastTransactionNum;
		
		this.accountNum = accountNum;
		this.type = type;
		this.money = money;
		
		DateFormat dateFormat = new SimpleDateFormat("yyyyMMdd");
		Calendar cal = Calendar.getInstance();
		transactionDate = dateFormat.format(cal.getTime());
		
		targetAccountNum = "";
	}
	
	public Transaction(String accountNum, int type, int money, String targetAccountNum) {
		transactionNum = ++lastTransactionNum;
		
		this.accountNum = accountNum;
		this.type = type;
		this.money = money;
		this.targetAccountNum = targetAccountNum;
		
		DateFormat dateFormat = new SimpleDateFormat("yyyyMMdd");
		Calendar cal = Calendar.getInstance();
		transactionDate = dateFormat.format(cal.getTime());
	}
	
	public Transaction(int transactionNum, String accountNum, String transactionDate, int type, int money, String targetAccountNum) {
		this.transactionNum = transactionNum;
		this.accountNum = accountNum;
		this.transactionDate = transactionDate;
		this.type = type;
		this.money = money;
		this.targetAccountNum = targetAccountNum;
	}
	
	public void initLastTransactionNum() {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "select * from transaction order by transactionNum desc limit 1;";
		
			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			ResultSet rs = pstmt.executeQuery();
			 
            if (rs.next()) {
            	lastTransactionNum = rs.getInt("transactionNum");
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
	
	public int getTransactionNum() {
		return transactionNum;
	}
	
	public String getAccountNum() {
		return accountNum;
	}
	
	public String getTransactionDate() {
		return transactionDate;
	}
	
	public int getType() {
		return type;
	}
	
	public int getMoney() {
		return money;
	}
	
	public String getTargetAccountNum() {
		return targetAccountNum;
	}
	
	public void registerTransaction() {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "insert into transaction values(?,?,?,?,?,?);";
		
			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setInt(1, transactionNum);
			pstmt.setString(2, accountNum);
			pstmt.setString(3, transactionDate);
			pstmt.setInt(4, type);
			pstmt.setInt(5, money);
			pstmt.setString(6, targetAccountNum);
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
	
	public ArrayList<Transaction> selectTransactionsByDate(String accountNum, String date) {
		String userId = "root";
		String password = "anstj0177";
		ArrayList<Transaction> tl = new ArrayList<Transaction>();
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "select * from transaction where (accountNum = ? or targetAccountNum = ?) and transactionDate >= ?;";
			
			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setString(1, accountNum);
			pstmt.setString(2, accountNum);
			pstmt.setString(3, date);
			ResultSet re = pstmt.executeQuery();
			 
            while (re.next()) {
            	Transaction t = null;
            	
            	int transactionNum = re.getInt("transactionNum");
            	String acNum = re.getString("accountNum");
            	String transactionDate = re.getString("transactionDate");
            	int type = re.getInt("type");
            	int money = re.getInt("money");
            	String targetAccountNum = re.getString("targetAccountNum");
            	
            	t = new Transaction(transactionNum, acNum, transactionDate, type, money, targetAccountNum);
            	tl.add(t);
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
        return tl;
	}
	
	public ArrayList<Transaction> selectTransactions(String accountNum) {
		String userId = "root";
		String password = "anstj0177";
		ArrayList<Transaction> tl = new ArrayList<Transaction>();
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "select * from transaction where accountNum = ? or targetAccountNum = ?;";
			
			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setString(1, accountNum);
			pstmt.setString(2, accountNum);
			ResultSet re = pstmt.executeQuery();
			 
            while (re.next()) {
            	Transaction t = null;
            	
            	int transactionNum = re.getInt("transactionNum");
            	String acNum = re.getString("accountNum");
            	String transactionDate = re.getString("transactionDate");
            	int type = re.getInt("type");
            	int money = re.getInt("money");
            	String targetAccountNum = re.getString("targetAccountNum");
            	
            	t = new Transaction(transactionNum, acNum, transactionDate, type, money, targetAccountNum);
            	tl.add(t);
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
        return tl;
	}
}
