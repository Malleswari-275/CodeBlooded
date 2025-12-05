start_time = pd.to_datetime('2019-01-01')
end_time =  pd.to_datetime('2019-03-31')
df = sales.groupby('product_id').filter(lambda x:
    min(x['sale_date']) >= start_time and max(x['sale_date']) <= end_time
)