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

public class ProductInformation implements Subject {
	private static int lastProductInformationNum = 1;
	
	private int productInformationNum;
	private String title;
	private String description;
	private String date;
	private ArrayList<Observer> observers;
	
	public ProductInformation() {}
	
	public ProductInformation(String title, String description ) {
		productInformationNum = ++lastProductInformationNum;
		this.title = title;
		this.description = description;
		
		DateFormat dateFormat = new SimpleDateFormat("yyyyMMdd");
		Calendar cal = Calendar.getInstance();
		date = dateFormat.format(cal.getTime());
		
		observers = new ArrayList<Observer>();
	}
	
	public ProductInformation(int piNum, String title, String description, String date) {
		this.productInformationNum = piNum;
		this.title = title;
		this.description = description;
		this.date = date;
		
		observers = new ArrayList<Observer>();
	}
	
	public void initLastPiNum() {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "select * from productInformation order by piNum desc limit 1;";
		
			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			ResultSet rs = pstmt.executeQuery();
			 
            if (rs.next()) {
            	lastProductInformationNum = rs.getInt("piNum");
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
	
	public int getProductInformationNum() {
		return productInformationNum;
	}
	
	public String getTitle() {
		return title;
	}
	
	public String getDescription() {
		return description;
	}
	
	public String getDate() {
		return date;
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
	
	public void registerProductInformation() {
		String userId = "root";
		String password = "anstj0177";
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "insert into productInformation values(?,?,?,?);";
		
			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			pstmt.setInt(1, productInformationNum);
			pstmt.setString(2, title);
			pstmt.setString(3, description);
			pstmt.setString(4, date);
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
	
	public ArrayList<ProductInformation> selectProductInforamtions() {
		String userId = "root";
		String password = "anstj0177";
		ArrayList<ProductInformation> pl = new ArrayList<ProductInformation>();
		
		Connection connection = null;
		PreparedStatement pstmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
			connection = (Connection) DriverManager.getConnection("jdbc:mysql://54.82.120.60:3306/mvc_pattern?useSSL=false&allowPublicKeyRetrieval=true", userId, password);

			String sql = "select * from productInformation;";
		
			pstmt = (PreparedStatement) connection.prepareStatement(sql);
			ResultSet re = pstmt.executeQuery();
			 
            while (re.next()) {
            	ProductInformation pi = null;
            	int piNum = re.getInt("piNum");
            	String t = re.getString("title");
            	String des = re.getString("description");
            	String date = re.getString("date");
            	
            	pi = new ProductInformation(piNum, t, des, date);
                pl.add(pi);
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
        return pl;
	}
}
