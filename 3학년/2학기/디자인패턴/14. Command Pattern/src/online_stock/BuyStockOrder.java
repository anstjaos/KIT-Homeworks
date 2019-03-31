package online_stock;

public class BuyStockOrder implements Order {
	private StockTrade stock;
	
	public BuyStockOrder(StockTrade stock) {
		this.stock = stock;
	}
	
	public void execute() {
		stock.buy();
	}
}
