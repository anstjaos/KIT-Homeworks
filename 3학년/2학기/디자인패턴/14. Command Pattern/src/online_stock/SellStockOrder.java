package online_stock;

public class SellStockOrder implements Order {
	private StockTrade stock;
	
	public SellStockOrder(StockTrade stock) {
		this.stock = stock;
	}
	
	public void execute() {
		stock.sell();
	}
}
