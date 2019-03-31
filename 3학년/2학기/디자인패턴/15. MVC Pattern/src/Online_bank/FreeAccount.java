package Online_bank;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class FreeAccount extends Account {
	public FreeAccount(String ownerId, int balance) {
		super(ownerId, balance, 0);
	}
	
	public FreeAccount(String accountNum, String ownerId, int balance, String createDate, int type) {
		super(accountNum, ownerId, balance, createDate, type);
	}
	
	public FreeAccount() {
	}

	public void registerAccount() {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "insert into account values(?,?,?,?,?,?);";
		
			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setString(1, accountNum);
			pstmt.setString(2, ownerId);
			pstmt.setInt(3, balance);
			pstmt.setString(4, createDate);
			pstmt.setInt(5, type);
			pstmt.setInt(6, 0);
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
	
	public boolean withdraw(int money) {
		if(balance - money < 0) return false;
		
		balance = balance - money;
		updateAccount();
		return true;
	}
}
