import { Client, QueryResult } from 'pg';

const client = new Client({
    connectionString: process.env.DATABASE_URL,
    ssl: {
        rejectUnauthorized: false
    }
});

client.connect();

export async function db_req(query: string, values?: any): Promise<QueryResult<any>> {
    try {
        return client.query(query, values);
    } catch (error) {
        throw error;
    }
}