// Create a 3D array with random values between min and max
const create3DArray = (rows, cols, depth, min, max) => {
  const array = [];
  for (let i = 0; i < rows; i++) {
    array.push([]);
    for (let j = 0; j < cols; j++) {
      array[i].push([]);
      for (let k = 0; k < depth; k++) {
        array[i][j].push(Math.floor(Math.random() * (max - min) + min));
      }
    }
  }
  return array;
};

// flatten the 3D Array into a 1D Vector
const convertToVector = (matrix) => {
  const vector = [];
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix[i].length; j++) {
      for (let k = 0; k < matrix[i][j].length; k++) {
        vector.push(matrix[i][j][k]);
      }
    }
  }
  return vector;
};

const retrieveRespectiveIndex = (n, m, p, i, j, k) => {
  const y = n * n * i + m * j + k;
  return y;
};

const assertEquals = (n, m, p, i, j, k) => {
  const _3DArray = create3DArray(n, m, p, 0, 100);
  const _1DVector = convertToVector(_3DArray);
  if (
    _1DVector[retrieveRespectiveIndex(n, m, p, i, j, k)] === _3DArray[i][j][k]
  ) {
    console.log('PASSED');
  } else {
    console.log('FAILED');
  }
};

assertEquals(10, 10, 10, 0, 0, 0);
assertEquals(10, 10, 10, 0, 0, 1);
assertEquals(10, 10, 10, 0, 1, 1);
assertEquals(10, 10, 10, 0, 1, 0);
assertEquals(10, 10, 10, 1, 0, 0);
assertEquals(10, 10, 10, 1, 0, 1);
assertEquals(10, 10, 10, 1, 1, 0);
assertEquals(10, 10, 10, 1, 1, 1);
assertEquals(10, 10, 10, 1, 2, 3);
assertEquals(10, 10, 10, 5, 5, 5);
assertEquals(10, 10, 10, 9, 7, 2);
assertEquals(10, 10, 10, 9, 9, 9);
