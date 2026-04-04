void dfs(int** image, int m, int n, int r, int c, int oldColor, int newColor) {
    // Boundary + color check
    if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != oldColor) {
        return;
    }

    // Change color
    image[r][c] = newColor;

    // Explore 4 directions
    dfs(image, m, n, r + 1, c, oldColor, newColor);
    dfs(image, m, n, r - 1, c, oldColor, newColor);
    dfs(image, m, n, r, c + 1, oldColor, newColor);
    dfs(image, m, n, r, c - 1, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize,
                int sr, int sc, int color,
                int* returnSize, int** returnColumnSizes) {
    
    int m = imageSize;
    int n = imageColSize[0];

    int oldColor = image[sr][sc];

    // Important edge case
    if (oldColor == color) {
        *returnSize = m;
        *returnColumnSizes = imageColSize;
        return image;
    }

    dfs(image, m, n, sr, sc, oldColor, color);

    *returnSize = m;
    *returnColumnSizes = imageColSize;

    return image;
}