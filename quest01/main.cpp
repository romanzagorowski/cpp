int main()
{
    int e = foo();
    if(e)
        handle_error(e);

    try
    {
    }
    catch(...)
    {
        handle_exception();
    }
}

