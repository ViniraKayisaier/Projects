public class pizza{
  private int m_cheese;
  private int m_pepo;
  private int m_veg;
  private String m_PizzaSize;
  // default
  public pizza(){
    m_PizzaSize = "Medium";
    m_cheese = 1;
    m_pepo = 0;
    m_veg = 0;
  }  // overload
  public pizza(String ps, int p, int c, int v){
    m_PizzaSize = ps;
    m_pepo = p;
    m_cheese = c;
    m_veg = v;
  }

  // copy construction
  public pizza(pizza pizzaToCopy){
    this.m_PizzaSize = pizzaToCopy.m_PizzaSize;
    this.m_pepo = pizzaToCopy.m_pepo;
    this.m_cheese = pizzaToCopy.m_cheese;
    this.m_veg = pizzaToCopy.m_veg;
  }
  // mutators and accessors
  // accessors (get):
   public String getPizzaSize(){
     return m_PizzaSize;
   }
   public int getVeg(){
     return m_veg;
   }
   public int getPepo (){
     return m_pepo;
   }
   public int getCheese(){
     return m_cheese;
   }
   // mutators (set):
   public void setPizzaSize (String newPizzasize){
     m_PizzaSize = newPizzasize;
   }
   public void setVeg (int newVeg){
     m_veg = newVeg;
   }
   public void setPepo (int newPepo){
     m_pepo = newPepo;
   }
   public void setCheese (int newCheese){
     m_cheese = newCheese;
   }
  //total cost calculation
  public double calcCost(){
    double Topping = m_veg + m_pepo + m_cheese;
    if (m_PizzaSize.equals("Small"))
			return 10 + Topping * 2;
		else if(m_PizzaSize.equals("Medium"))
			return 12 + Topping * 2;
		else if(m_PizzaSize.equals("Large"))
			return 14 + Topping * 2;
    else
			return 0.0;
  }
      // toString method
  public String toString(){
   String p = "";
   p += "Pizza Size " + m_PizzaSize;
   p += "\nCheese Topping: " + m_cheese;
   p += "\nPeporoni Topping: " + m_pepo;
   p += "\nVeggie Topping: " + m_veg;
   p += "\nTotal Cost per Pizza: " + calcCost();
   return p;
  }
  // boolean
  public boolean equals(Object o){
    if (!(o instanceof pizza)){
      return false;
    }
    pizza c = (pizza) o;
    if ((this.m_veg == c.m_veg)&&(this.m_pepo == c.m_pepo)&&(this.m_cheese == c.m_cheese)){
      return true;
    if(this.m_PizzaSize.equals(c.m_PizzaSize))
      return true;
    }
    return false;
  }
}
