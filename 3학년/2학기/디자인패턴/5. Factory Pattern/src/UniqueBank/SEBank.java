package UniqueBank;

public class SEBank {
	protected String branchName;
	private BankFactory bf;
	
	public SEBank(BankFactory bankFactory) { bf = bankFactory; } 
	
	public Account newAccount(String accountType) {
		Account ac = bf.createAccount(accountType, branchName);
		
		return ac;
	}
	
	public String getBranchName() { return branchName; }
}
