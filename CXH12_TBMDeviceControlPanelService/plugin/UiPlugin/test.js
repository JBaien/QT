function OperatorNumber(number)
{
    this.number = number;
    this.add = function(num)
    {
        return number + num
    }
    this.sub = function(num)
    {
        return number - num
    }
}
